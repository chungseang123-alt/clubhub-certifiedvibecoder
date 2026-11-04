#pragma once
#include <chrono>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace clubhub {

enum class SyncState { Pending, Sent, Accepted, Rejected };

struct QueuedCheckIn {
    std::string localId;
    std::string deviceId;
    std::string eventId;
    std::string studentId;
    std::chrono::sys_seconds scannedAt{}; 
    unsigned int attempts{0};
    SyncState state{SyncState::Pending};
    std::optional<std::string> rejectReason{};
};

class CheckInQueue {
public:
    bool enqueue(QueuedCheckIn item) {
        if (item.localId.empty() || item.deviceId.empty() ||
            item.eventId.empty() || item.studentId.empty()) return false;
        for (const auto& existing : items_) {
            if (existing.localId == item.localId) return false;
            if (existing.eventId == item.eventId &&
                existing.studentId == item.studentId &&
                existing.state != SyncState::Rejected) return false;
        }
        item.state = SyncState::Pending;
        item.attempts = 0;
        item.rejectReason.reset();
        items_.push_back(std::move(item));
        return true;
    }

    std::vector<QueuedCheckIn> pending() const {
        std::vector<QueuedCheckIn> result;
        for (const auto& item : items_) {
            if (item.state == SyncState::Pending || item.state == SyncState::Sent)
                result.push_back(item);
        }
        return result;
    }

    void markSent(const std::string& localId) {
        for (auto& item : items_) {
            if (item.localId == localId &&
                (item.state == SyncState::Pending || item.state == SyncState::Sent)) {
                item.state = SyncState::Sent;
                ++item.attempts;
                return;
            }
        }
    }

    void markAccepted(const std::string& localId) {
        for (auto& item : items_) {
            if (item.localId == localId && item.state != SyncState::Rejected) {
                item.state = SyncState::Accepted;
                item.rejectReason.reset();
                return;
            }
        }
    }

    void markRejected(const std::string& localId, std::string reason) {
        for (auto& item : items_) {
            if (item.localId == localId && item.state != SyncState::Accepted) {
                item.state = SyncState::Rejected;
                item.rejectReason = std::move(reason);
                return;
            }
        }
    }

private:
    std::vector<QueuedCheckIn> items_;
};

} // namespace clubhub
