cmake_minimum_required(VERSION 3.18)
project(battle_city)

set(MAIN_DIRECTORY main)
set(CMAKE_CXX_STANDARD 20)
set(MAIN
        ${MAIN_DIRECTORY}/main.cpp
        ${MAIN_DIRECTORY}/types/iwindow.hpp
        ${MAIN_DIRECTORY}/types/igame.hpp
        ${MAIN_DIRECTORY}/game.cpp
        ${MAIN_DIRECTORY}/game.hpp
        ${MAIN_DIRECTORY}/window.cpp
        ${MAIN_DIRECTORY}/window.hpp
        )

add_subdirectory(SFML)
add_subdirectory(mingw-std-threads)

add_executable(battle_city ${MAIN})
target_link_libraries(battle_city sfml-graphics mingw_stdthreads)