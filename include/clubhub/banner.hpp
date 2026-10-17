// include/clubhub/banner.hpp
#pragma once

#include <string>
#include <string_view>

namespace clubhub {

// The team name printed at start-up. TODO: your team name.
inline constexpr std::string_view kTeamName = "CertifiedVibeCoder";

// Returns the start-up banner, one line per row, ending in '\n'.
[[nodiscard]] std::string banner(std::string_view teamName);

}  // namespace clubhub