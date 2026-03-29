cmake_minimum_required(VERSION 4.2)
project(cosmos)

set(CMAKE_CXX_STANDARD 26)

add_executable(cosmos
        src/main.cpp
        src/Rocket.hpp
        src/Rocket.cpp)
