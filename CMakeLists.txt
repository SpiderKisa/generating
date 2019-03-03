cmake_minimum_required(VERSION 3.13)
project(generating)

set(CMAKE_CXX_STANDARD 17)

add_executable(generating main.cpp src/gnrt.h src/gnrt.cpp)