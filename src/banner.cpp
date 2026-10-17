// src/banner.cpp
#include "include/clubhub/banner.hpp"

namespace clubhub {

std::string banner(std::string_view teamName) {
    const std::string rule(40, '=');
    std::string out;
    // TODO: rule, "  ITC Club Hub  v" CLUBHUB_VERSION, "  Team: " + teamName,
    //       rule; every line ends in '\n'
    (void)teamName;
    return out;
}

}  // namespace clubhub