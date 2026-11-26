# Reuse Inventory - ITC Club Hub

| Need | Options considered | Decision | Reason | Licence | Pinned version | Evidence the project is maintained (date of the last release) |
|---|---|---|---|---|---|---|
| Unit testing | GoogleTest, Catch2, writing our own asserts | Reuse | Easy to set up with CMake/CTest and already the standard for C++ testing | BSD-3-Clause | v1.17.0 | Still actively updated on GitHub (v1.17.0; newest release v1.18.0 on 2026-08-10) |
| File storage (CSV) | rapidcsv, writing our own CSV parser | Reuse | Header-only so no extra build hassle, and saves us from dealing with edge-case CSV parsing bugs | BSD-3-Clause | v8.84 | Actively maintained on GitHub (v8.84; newest release v9.07 on 2026-08-14) |
| Date and time (24-hour rule) | C++20 `<chrono>`, Howard Hinnant date lib | Build | `<chrono>` is already built into C++20 and does everything we need for 24-hour checks | MIT (project) | C++20 stdlib | Part of the official ISO C++20 standard library |
| CLI input handling | CLI11, `std::cin` / `std::getline` helpers | Build | Our CLI menus are pretty simple, so writing basic input helpers with `std::getline` is faster than learning a whole CLI library | MIT (project) | C++20 stdlib | Built in-house for Club Hub |
| Registration rules | Custom domain logic | Build | Capacity limits, duplicate checks, and club rules are specific to our project so no library will do this for us | MIT (project) | N/A (in-repo) | Built in-house for Club Hub |
| Reminders | Cron/scheduler library, simple check on startup | Defer | Not needed for the core build right now, we can add this later once basic registration works | MIT (project) | Deferred | Deferred to a later lab |
| Monthly report | Report generator library, custom text formatter | Defer | Out of scope for the smoke test and initial core slice, so we'll build it later | MIT (project) | Deferred | Deferred to a later lab |
| Logging | spdlog, basic console/file logger | Defer | Plain console prints are enough for now; we can add proper logging later if needed | MIT (project) | Deferred | Deferred to a later lab |

## Licence Compatibility Check

* **GoogleTest (BSD-3-Clause):** Works fine with our **MIT** repo licence. BSD-3-Clause is permissive, so we can use and link it in an MIT project as long as we keep its copyright and licence notice in the repo.
* **rapidcsv (BSD-3-Clause):** Also compatible with our **MIT** licence. Since it's permissive, we can include the header in our project without changing our MIT licence, just keeping their copyright notice intact.
* **What a GPL library would require:** GPL (like GPL-3.0) is a strong copyleft licence. If we linked a GPL library into our app and distributed it, we would be forced to release the entire project under GPL too and share all the source code under GPL terms, which doesn't work if we want to keep the repo under permissive MIT terms.

## Verification
```text
cmake version 4.4.4
g++.exe (Rev11, Built by MSYS2 project) 15.2.0

-- The CXX compiler identification is GNU 15.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/msys64/ucrt64/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- The C compiler identification is GNU 15.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/msys64/ucrt64/bin/cc.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Using build type 'Debug' (default).
-- Build tests: OFF
-- Install/uninstall targets disabled.
-- Configuring done (18.6s)
-- Generating done (0.1s)
-- Build files have been written to: C:/Users/ROG/clubhub-certifiedvibecoder/build
[ 10%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
[ 20%] Linking CXX static library ..\..\..\lib\libgtest.a
[ 20%] Built target gtest
[ 30%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj
[ 40%] Linking CXX static library ..\..\..\lib\libgtest_main.a
[ 40%] Built target gtest_main
[ 50%] Building CXX object CMakeFiles/csv_smoke_test.dir/tests/csv_smoke_test.cpp.obj
[ 60%] Linking CXX executable csv_smoke_test.exe
[ 60%] Built target csv_smoke_test
[ 70%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj
[ 80%] Linking CXX static library ..\..\..\lib\libgmock.a
[ 80%] Built target gmock
[ 90%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj
[100%] Linking CXX static library ..\..\..\lib\libgmock_main.a
[100%] Built target gmock_main
Test project C:/Users/ROG/clubhub-certifiedvibecoder/build
    Start 1: CsvSmokeTest.ReadEventTitlesAndCapacities
1/1 Test #1: CsvSmokeTest.ReadEventTitlesAndCapacities ...   Passed    0.02 sec

100% tests passed out of 1

Total Test time (real) =   0.09 sec
```
