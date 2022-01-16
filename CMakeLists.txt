cmake_minimum_required(VERSION 3.18)
project(battle_city)

set(CMAKE_CXX_STANDARD 20)

set(MAIN_DIRECTORY main)
set(PICTURE_DIRECTORY picture)
set(RESOURCE_DIRECTORY resource)

set(MAIN
        ${MAIN_DIRECTORY}/main.cpp
        ${MAIN_DIRECTORY}/types/iwindow.hpp
        ${MAIN_DIRECTORY}/types/igame.hpp
        ${MAIN_DIRECTORY}/game.cpp
        ${MAIN_DIRECTORY}/game.hpp
        ${MAIN_DIRECTORY}/window.cpp
        ${MAIN_DIRECTORY}/window.hpp
        )

set(RESOURCE
        ${RESOURCE_DIRECTORY}/png/manager.hpp
        ${RESOURCE_DIRECTORY}/png/manager.cpp
        ${RESOURCE_DIRECTORY}/ini/ini_reader.hpp
        ${RESOURCE_DIRECTORY}/ini/ini_reader.cpp
        ${RESOURCE_DIRECTORY}/ini/parser.hpp
        ${RESOURCE_DIRECTORY}/ini/parser.cpp
        )

set(PICTURE
        ${PICTURE_DIRECTORY}/picture_builder.cpp
        ${PICTURE_DIRECTORY}/picture_builder.hpp
        )

add_subdirectory(SFML)
add_subdirectory(mingw-std-threads)

add_executable(${PROJECT_NAME} ${MAIN} ${PICTURE} ${RESOURCE})
target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} sfml-graphics mingw_stdthreads)