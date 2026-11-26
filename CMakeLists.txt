# CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(Clubhub VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Library: all code except main(); later labs link tests to it
# add_library(clubhub_core src/banner.cpp)
# target_include_directories(clubhub_core PUBLIC include)

# Core: domain model and rules. No console, no file names.
# target_include_directories(clubhub_core PUBLIC include)
add_library(clubhub_core
  src/event.cpp
  src/event_csv.cpp
  src/Student.cpp
  src/ConsoleOutput.cpp
)
target_include_directories(clubhub_core PUBLIC include)
target_compile_definitions(clubhub_core
    PRIVATE CLUBHUB_VERSION="0.1.0")
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()
    target_include_directories(clubhub_core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Executable: the command-line front end
# add_executable(clubhub src/main.cpp)
# target_link_libraries(clubhub PRIVATE clubhub_core)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# Windows/MSVC: use the same runtime library as the project
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest rapidcsv)
FetchContent_Declare(
    rapidcsv
    GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
    GIT_TAG v8.84
    GIT_SHALLOW TRUE
)

enable_testing()
include(GoogleTest)
add_executable(clubhub_tests
  tests/StudentPrivacyTest.cpp
  tests/ConsoleOutputTest.cpp)
target_link_libraries(clubhub_tests PRIVATE clubhub_core GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(clubhub_tests)

# Interface: the command-line front end. A web or mobile front end
# would be another target that links the same core.
add_executable(clubhub src/cli/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)
add_executable(csv_smoke_test 
    tests/csv_smoke_test.cpp
)
target_link_libraries(csv_smoke_test PRIVATE rapidcsv GTest::gtest_main)
gtest_discover_tests(csv_smoke_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(cancellation_rule_test 
    tests/cancellation_rule_test.cpp
)
target_include_directories(cancellation_rule_test PRIVATE include)
target_link_libraries(cancellation_rule_test PRIVATE GTest::gtest_main)
gtest_discover_tests(cancellation_rule_test)
