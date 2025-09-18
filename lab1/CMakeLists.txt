cmake_minimum_required(VERSION 3.14)
project(Lab1_RemoveVowels)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Основной исполняемый файл
add_executable(lab1
    src/main.cpp
    src/remove_vowels.cpp
)

target_include_directories(lab1 PRIVATE include)

# Google Test
enable_testing()
# найди пакет GTest из vcpkg
find_package(GTest CONFIG REQUIRED)

add_executable(tests
    tests/test_remove_vowels.cpp
    src/remove_vowels.cpp
)

target_include_directories(tests PRIVATE include)

# правильные цели из vcpkg
target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
