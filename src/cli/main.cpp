// SPDX-License-Identifier: MIT
// Copyright (c) 2026 certifiedvibecoder, ITC Club Hub contributors
// src/cli/main.cpp: the only place that talks to the user
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "clubhub/event.hpp"
#include "clubhub/event_csv.hpp"

namespace {

int listEvents(const std::string& path) {
    std::ifstream file{path};
    if (!file) {
        std::cerr << "error: cannot open " << path << '\n';
        return 2;
    }
    auto [events, errors] = clubhub::loadEventsCsv(file);
    std::ranges::sort(events, {}, &clubhub::Event::start);
    std::cout << std::left << std::setw(18) << "START"
              << std::setw(22) << "TITLE" << std::setw(15) << "LOCATION"
              << "CAPACITY\n";
    for (const auto& event : events) {
        std::cout << std::left << std::setw(18) << clubhub::formatTimePoint(event.start())
                  << std::setw(22) << event.title()
                  << std::setw(15) << event.location()
                  << event.capacity() << '\n';
    }
    std::cout << events.size() << " event(s)\n";
    for (const auto& error : errors) {
        std::cerr << path << ':' << error.line << ": skipped: " << error.message << '\n';
    }
    return errors.empty() ? 0 : 1;
}

void printUsage() {
    std::cerr << "usage: clubhub list-events [events.csv]\n";
}

} // namespace

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 2;
    }
    const std::string command{argv[1]};
    if (command == "list-events") {
        return listEvents(argc > 2 ? argv[2] : "data/events.csv");
    }
    std::cerr << "unknown command: " << command << '\n';
    printUsage();
    return 2;
}