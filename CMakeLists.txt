cmake_minimum_required(VERSION 3.15)
project(cp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_executable(cp test.cpp)