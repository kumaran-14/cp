cmake_minimum_required(VERSION 3.15)
project(cp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cp test.cpp cpp/Algorithms/Math/product.cpp)