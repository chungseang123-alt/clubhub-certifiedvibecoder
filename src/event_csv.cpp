// SPDX-License-Identifier: MIT
// Copyright (c) 2026 certifiedvibecoder, ITC Club Hub contributors
// src/event_csv.cpp
#include "clubhub/event_csv.hpp"

#include <sstream>
#include <stdexcept>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;
    std::getline(in, line);  // skip the header
    while (std::getline(in, line)) {
        ++lineNo;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        try {
            std::vector<std::string> fields;
            std::size_t begin = 0;
            for (;;) {
                const auto comma = line.find(',', begin);
                if (comma == std::string::npos) {
                    fields.push_back(line.substr(begin));
                    break;
                }
                fields.push_back(line.substr(begin, comma - begin));
                begin = comma + 1;
            }
            if (fields.size() != 5) {
                throw std::invalid_argument{"expected exactly 5 fields"};
            }
            std::size_t consumed = 0;
            int capacity{};
            try {
                capacity = std::stoi(fields[4], &consumed);
            } catch (const std::out_of_range&) {
                throw std::invalid_argument{"invalid capacity"};
            } catch (const std::invalid_argument&) {
                throw std::invalid_argument{"invalid capacity"};
            }
            if (consumed != fields[4].size()) {
                throw std::invalid_argument{"invalid capacity"};
            }
            result.events.emplace_back(fields[0], fields[1],
                                       parseTimePoint(fields[2]), fields[3], capacity);
            } 
        catch (const std::invalid_argument& e) {
            result.errors.push_back({lineNo, e.what()});
        }
    }
    return result;
}

} // namespace clubhub