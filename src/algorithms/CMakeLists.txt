cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(test_algo)

include_directories(../../inc)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions("-Wall -g")

file(GLOB_RECURSE SRC_FILES math/*.cpp misc/*.cpp sort/*.cpp str/*.cpp test.cpp)

message(STATUS $(SRC_FILES))
add_executable(test_algo ${SRC_FILES})
