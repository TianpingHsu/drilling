cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

find_package(Catch2 3 REQUIRED)

SET(PROJ_NAME test_algo)

project(${PROJ_NAME})

include_directories(./inc)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -g")
add_definitions("-Wall -g")

add_compile_options(-Wno-sign-compare)
add_compile_options(-Wno-unused-variable)


file(GLOB_RECURSE SRC_FILES
	math/*.cpp
	misc/*.cpp
    misc/prefix_sum/*.cpp
	sort/*.cpp
	str/*.cpp
	dp/*.cpp
    ./utils.cpp
    search/*.cpp
    )

message(STATUS $(SRC_FILES))
add_executable(${PROJ_NAME} ${SRC_FILES})

target_link_libraries(${PROJ_NAME} PRIVATE Catch2::Catch2WithMain)
