cmake_minimum_required(VERSION 3.28)
project(ClubHub VERSION 0.4.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(rapidcsv
  GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
  GIT_TAG        v8.84
  GIT_SHALLOW    TRUE)

FetchContent_MakeAvailable(googletest rapidcsv)

enable_testing()
include(GoogleTest)

add_executable(csv_smoke_test tests/csv_smoke_test.cpp)
target_link_libraries(csv_smoke_test PRIVATE rapidcsv GTest::gtest_main)
gtest_discover_tests(csv_smoke_test
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
