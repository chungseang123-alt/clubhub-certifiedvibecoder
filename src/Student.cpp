// SPDX-License-Identifier: MIT
// Copyright (c) 2026 certifiedvibecoder, ITC Club Hub contributors
// src/Student.cpp
#include "clubhub/Student.h"
#include <stdexcept>
#include <cctype>

namespace clubhub {

std::string maskId(std::string_view id) {
    if (id.length() <= 4) return std::string(id.length(), '*');
    // e.g. "e20990417" -> "e2******7"
    return std::string(id.substr(0, 2)) +
           std::string(id.length() - 3, '*') +
           id.back();
}

Student::Student(std::string id, std::string name, std::string email)
    : id_(std::move(id)), name_(std::move(name)), email_(std::move(email)) {
    if (id_.empty()) {
        throw std::invalid_argument("Student ID cannot be empty");
    }
    if (name_.empty()) {
        throw std::invalid_argument("Student Name cannot be empty");
    }
    if (email_.find('@') == std::string::npos) {
        throw std::invalid_argument("Email must contain '@'");
    }
}

void Student::giveSmsConsent(std::string phone) {
    if (phone.find_first_of("0023456789") == std::string::npos ||
        phone.find_first_not_of("0023456789+ ") != std::string::npos) {
        throw std::invalid_argument{"Phone must contain digits and may include + and spaces"};
    }
    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept {
    phone_.reset();
}

std::string Student::redacted() const {
    auto masked = maskId(id_);
    for (char& character : masked) {
        const auto byte = static_cast<unsigned char>(character);
        if (byte < 0x20 || byte > 0x7e) {
            character = '*';
        }
    }
    return "Student{id=" + masked + "}";
}

} // namespace clubhub
