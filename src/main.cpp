// SPDX-License-Identifier: MIT
// Copyright (c) 2026 certifiedvibecoder, ITC Club Hub contributors
// src/main.cpp
#include <iostream>

#include "clubhub/banner.hpp"

int main() {
    std::cout << clubhub::banner(clubhub::kTeamName);
    std::cout << "Commands arrive in a later lab. Bye!\n";
    return 0;
}