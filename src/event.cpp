// SPDX-License-Identifier: MIT
// Copyright (c) 2026 certifiedvibecoder, ITC Club Hub contributors
#include "clubhub/event.hpp"

#include <cctype>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace clubhub {

Event::Event(std::string id, std::string title, TimePoint start,
             std::string location, int capacity)
    : id_{std::move(id)}, title_{std::move(title)}, start_{start},
      location_{std::move(location)}, capacity_{capacity} {
    if (id_.empty()) {
        throw std::invalid_argument{"id must not be empty"};
    }
    if (title_.empty()) {
        throw std::invalid_argument{"title must not be empty"};
    }
    if (capacity_ <= 0) {
        throw std::invalid_argument{"capacity must be positive"};
    }
}

TimePoint parseTimePoint(const std::string& text) {
    using namespace std::chrono;
    const auto invalid = [&text]() {
        throw std::invalid_argument{"bad date-time '" + text + "'"};
    };
    if (text.size() != 16 || text[4] != '-' || text[7] != '-' ||
        text[10] != ' ' || text[13] != ':') {
        invalid();
    }
    for (std::size_t i = 0; i < text.size(); ++i) {
        if (i == 4 || i == 7 || i == 10 || i == 13) continue;
        if (!std::isdigit(static_cast<unsigned char>(text[i]))) invalid();
    }
    const int y = std::stoi(text.substr(0, 4));
    const int mo = std::stoi(text.substr(5, 2));
    const int d = std::stoi(text.substr(8, 2));
    const int h = std::stoi(text.substr(11, 2));
    const int mi = std::stoi(text.substr(14, 2));
    const year_month_day date{year{y}, month{static_cast<unsigned>(mo)},
                              day{static_cast<unsigned>(d)}};
    return sys_days{date} + hours{h} + minutes{mi};
}

// Given: TimePoint -> "2026-10-14 14:00"
std::string formatTimePoint(TimePoint t) {
    using namespace std::chrono;
    const auto midnight = floor<days>(t);
    const year_month_day date{midnight};
    const hh_mm_ss time{t - midnight};
    std::ostringstream out;
    out << std::setfill('0') << static_cast<int>(date.year()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.month()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.day()) << ' '
        << std::setw(2) << time.hours().count() << ':'
        << std::setw(2) << time.minutes().count();
    return out.str();
}

} // namespace clubhub