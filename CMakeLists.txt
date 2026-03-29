cmake_minimum_required(VERSION 4.2)
project(cosmos)

set(CMAKE_CXX_STANDARD 26)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(
        $(PROJECT_NAME)
        src/main.cpp
        src/Rocket.hpp
        src/Rocket.cpp
        src/Star.cpp
        src/Star.hpp
        src/ParticleSystem.cpp
        src/ParticleSystem.hpp
        src/Game.cpp
        src/Game.hpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
target_include_directories(${PROJECT_NAME} PRIVATE src)
