cmake_minimum_required(VERSION 3.10)

project(names)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library (
	person
	person.cpp
)

add_executable(persons main.cpp)
target_link_libraries(persons person)
