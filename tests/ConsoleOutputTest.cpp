// tests/ConsoleOutputTest.cpp
#include "gtest/gtest.h"

#include <cstdlib>
#include <string>

#include "clubhub/ConsoleOutput.h"

using clubhub::RegistrationStatus;

namespace {
// Portable set/unset of an environment variable for the NO_COLOR test.
void setEnv(const char* name, const char* value) {
#ifdef _WIN32
    _putenv_s(name, value);
#else
    setenv(name, value, 1);
#endif
}
void unsetEnv(const char* name) {
#ifdef _WIN32
    _putenv_s(name, "");  // an empty value removes the variable on Windows
#else
    unsetenv(name);
#endif
}
}  // namespace

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    EXPECT_EQ(clubhub::formatStatus(RegistrationStatus::Cancelled, false), "[CANCELLED]");
    EXPECT_EQ(clubhub::formatStatus(RegistrationStatus::CheckedIn, false), "[CHECKED IN]");
    EXPECT_EQ(clubhub::formatStatus(RegistrationStatus::Waitlisted, false), "[WAITLISTED]");
    EXPECT_EQ(clubhub::formatStatus(RegistrationStatus::Registered, false), "[REGISTERED]");
}

TEST(ConsoleOutput, ColourOnlyRepeatsTheWord) {
    for (auto s : {RegistrationStatus::Registered, RegistrationStatus::Cancelled,
                   RegistrationStatus::CheckedIn, RegistrationStatus::Waitlisted}) {
        const std::string plain = clubhub::formatStatus(s, false);
        const std::string coloured = clubhub::formatStatus(s, true);
        EXPECT_NE(coloured.find(plain), std::string::npos) << plain;  // word still there
        EXPECT_NE(coloured.find("\x1b["), std::string::npos);         // colour added
        EXPECT_EQ(coloured.substr(coloured.size() - 4), "\x1b[0m");   // always reset
    }
}

TEST(ConsoleOutput, ErrorSaysWhatWhyAndNextStep) {
    const std::string msg = clubhub::formatError(
        "cannot register for E-017", "the event is full (40 of 40 seats)",
        "clubhub waitlist E-017");
    EXPECT_EQ(msg,
              "Error: cannot register for E-017: the event is full (40 of 40 seats).\n"
              "Next step: clubhub waitlist E-017");
    EXPECT_NE(msg.find("Next step:"), std::string::npos);
}

TEST(ConsoleOutput, NoColourFlagAndEnvironmentDisableColour) {
    unsetEnv("NO_COLOR");
    EXPECT_TRUE(clubhub::colourEnabled(false));
    EXPECT_FALSE(clubhub::colourEnabled(true));   // --no-color wins

    setEnv("NO_COLOR", "1");
    EXPECT_FALSE(clubhub::colourEnabled(false));  // NO_COLOR wins

    unsetEnv("NO_COLOR");
}
