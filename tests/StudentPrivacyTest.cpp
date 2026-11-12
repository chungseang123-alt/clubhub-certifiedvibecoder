// SPDX-License-Identifier: MIT
// Copyright (c) 2026 certifiedvibecoder, ITC Club Hub contributors
// tests/StudentPrivacyTest.cpp
#include "clubhub/Student.h"

#include <gtest/gtest.h>

#include <stdexcept>

using clubhub::maskId;
using clubhub::Student;

// Invented test data only: never real students.
TEST(StudentPrivacy, RedactedHidesPersonalData) {
    Student s{"e27990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("002 345 678");
    const std::string r = s.redacted();
    EXPECT_EQ(r, "Student{id=e2******7}");
    EXPECT_EQ(r.find(s.id()), std::string::npos);
    EXPECT_EQ(r.find(s.name()), std::string::npos);
    EXPECT_EQ(r.find(s.email()), std::string::npos);
    ASSERT_TRUE(s.phone().has_value());
    EXPECT_EQ(r.find(*s.phone()), std::string::npos);
}
TEST(StudentPrivacy, OptionalConsentsStartOff) {
    const Student s{"e28990417", "Test Student", "test@example.com"};
    EXPECT_FALSE(s.remindersByEmail());
    EXPECT_FALSE(s.phone().has_value());
}
TEST(StudentPrivacy, WithdrawingSmsConsentErasesPhone) {
    Student s{"e23990417", "Test Student", "test@example.edu.kh"};
    s.setEmailReminders(true);
    s.giveSmsConsent("+855 02 345 678");
    ASSERT_TRUE(s.phone().has_value());
    EXPECT_EQ(*s.phone(), "+855 02 345 678");
    s.withdrawSmsConsent();
    s.withdrawSmsConsent();
    EXPECT_FALSE(s.phone().has_value());
    EXPECT_TRUE(s.remindersByEmail());
}
TEST(StudentPrivacy, RejectsEmailWithoutAt) {
    EXPECT_THROW((Student{"e20990417", "A", "no-at-sign"}),
                 std::invalid_argument);
}
TEST(StudentPrivacy, RejectsEmptyIdOrName) {
    EXPECT_THROW((Student{"", "Test Student", "test@example.edu"}),
                 std::invalid_argument);
    EXPECT_THROW((Student{"e20990417", "", "test@example.edu"}),
                 std::invalid_argument);
}
TEST(StudentPrivacy, RejectsPhoneWithLetters) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_THROW(s.giveSmsConsent("012 ABC 678"), std::invalid_argument);
    EXPECT_FALSE(s.phone().has_value());

    s.giveSmsConsent("002 345 678");
    EXPECT_THROW(s.giveSmsConsent("002 ABC 678"), std::invalid_argument);
    ASSERT_TRUE(s.phone().has_value());
    EXPECT_EQ(*s.phone(), "002 345 678");
}
TEST(StudentPrivacy, RejectsPhoneWithoutDigits) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_THROW(s.giveSmsConsent(""), std::invalid_argument);
    EXPECT_THROW(s.giveSmsConsent("+  "), std::invalid_argument);
    EXPECT_FALSE(s.phone().has_value());
}
TEST(StudentPrivacy, MaskIdHidesShortIdsCompletely) {
    EXPECT_EQ(maskId(""), "");
    EXPECT_EQ(maskId("x"), "*");
    EXPECT_EQ(maskId("x1"), "**");
    EXPECT_EQ(maskId("x12"), "***");
    EXPECT_EQ(maskId("x123"), "****");
}
TEST(StudentPrivacy, RedactedDoesNotIncludeLineBreaksFromId) {
    const Student s{"\ne02\r", "Test Student", "test@example.edu"};
    EXPECT_EQ(s.redacted(), "Student{id=*e***}");
}
TEST(StudentPrivacy, WithdrawingEmailConsentKeepsSmsConsent) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("002 345 678");
    s.setEmailReminders(true);
    s.setEmailReminders(false);
    EXPECT_FALSE(s.remindersByEmail());
    ASSERT_TRUE(s.phone().has_value());
    EXPECT_EQ(*s.phone(), "002 345 678");
}
