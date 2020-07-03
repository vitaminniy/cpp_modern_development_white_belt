cmake_minimum_required(VERSION 3.10)
project(move_strings)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
	move_strings
	move_strings.cpp
)
