#include <gtest/gtest.h>
#include "clubhub/CancellationPolicy.hpp"

using namespace std::chrono;
using clubhub::canCancel;

namespace {
constexpr sys_seconds start =
    sys_days{2026y / November / 7} + 14h;
}

TEST(CancellationPolicyTest, AllowsExactly24HoursBefore) {
    EXPECT_TRUE(canCancel(start - 24h, start));
}

TEST(CancellationPolicyTest, RejectsOneSecondTooLate) {
    EXPECT_FALSE(canCancel(start - 24h + 1s, start));
}

TEST(CancellationPolicyTest, AllowsOneWeekBefore) {
    EXPECT_TRUE(canCancel(start - 7d, start));
}

TEST(CancellationPolicyTest, RejectsAfterEventStarts) {
    EXPECT_FALSE(canCancel(start + 1s, start));
}
