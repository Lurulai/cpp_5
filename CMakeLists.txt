cmake_minimum_required(VERSION 3.22)
project(Assignment5)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assignment5 main.cpp Tracker.cpp Tracker.h DynamicArray.cpp DynamicArray.h FileWriter.cpp FileWriter.h)

target_compile_options(Assignment5 PRIVATE -Wall -Wextra -pedantic)
