cmake_minimum_required(VERSION 4.2)
project(cosmos)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Rocket.cpp
        src/Star.cpp
        src/ParticleSystem.cpp
        src/Game.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Window SFML::System)
target_include_directories(${PROJECT_NAME} PRIVATE src)