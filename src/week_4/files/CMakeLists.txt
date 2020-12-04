cmake_minimum_required(VERSION 3.18)

project(invertible_function LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(first first.cpp)
add_executable(second second.cpp)
