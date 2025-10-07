cmake_minimum_required(VERSION 3.14)
project(OOP_Lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Библиотека с классом Octal
add_library(octal_lib src/Octal.cpp)
target_include_directories(octal_lib PUBLIC include)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Тесты
enable_testing()
add_executable(octal_tests tests/test_octal.cpp)
target_link_libraries(octal_tests octal_lib gtest_main)

add_test(NAME OctalTests COMMAND octal_tests)
