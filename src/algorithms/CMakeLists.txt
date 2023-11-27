cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

find_package(Catch2 3 REQUIRED)

project(test_algo)

include_directories(./inc)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -g")
add_definitions("-Wall -g")

file(GLOB_RECURSE SRC_FILES
	math/*.cpp
	misc/*.cpp
	sort/*.cpp
	str/*.cpp
	dp/*.cpp
    ./utils.cpp
    )

message(STATUS $(SRC_FILES))
add_executable(test_algo ${SRC_FILES})

target_link_libraries(test_algo PRIVATE Catch2::Catch2WithMain)
