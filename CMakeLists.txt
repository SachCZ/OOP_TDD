cmake_minimum_required(VERSION 3.16)
project(OOP_TDD)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)
add_executable(mock_example test_service.cpp Service.h)
target_link_libraries(mock_example gtest gmock)