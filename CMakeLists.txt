# cmake_minimum_required(VERSION <specify CMake version here>)
project(Re2cStudy)

set(CMAKE_CXX_STANDARD 14)

add_executable(Re2cStudy main.cpp json_scanner.cpp json_parser.tab.cpp)