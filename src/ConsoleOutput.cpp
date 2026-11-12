// SPDX-License-Identifier: MIT
// Copyright (c) 2026 certifiedvibecoder, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"
#include <cstdlib>

namespace clubhub {

std::string_view statusLabel(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered: return "REGISTERED";
        case RegistrationStatus::Cancelled:  return "CANCELLED";
        case RegistrationStatus::CheckedIn:  return "CHECKED IN";
        case RegistrationStatus::Waitlisted: return "WAITLISTED";
    }
    return "UNKNOWN";
}

bool colourEnabled(bool noColorFlag) {
    if (noColorFlag) return false;
    const char* env = std::getenv("NO_COLOR");
    return !(env != nullptr && env[0] != '\0');
}

std::string formatStatus(RegistrationStatus s, bool colour) {
    std::string text = "[" + std::string(statusLabel(s)) + "]";
    if (!colour) return text;

    const char* code = "0";
    switch (s) {
        case RegistrationStatus::Registered: code = "32"; break; // green
        case RegistrationStatus::Cancelled:  code = "31"; break; // red
        case RegistrationStatus::CheckedIn:  code = "36"; break; // cyan
        case RegistrationStatus::Waitlisted: code = "33"; break; // yellow
    }
    return std::string("\033[") + code + "m" + text + "\033[0m";
}

std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next) {
    std::string out = "Error: ";
    out += what;
    out += ": ";
    out += why;
    out += ".\nNext step: ";
    out += next;
    return out;
}

} // namespace clubhub
