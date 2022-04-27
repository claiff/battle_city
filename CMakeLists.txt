cmake_minimum_required(VERSION 3.22)
project(battle_city)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}  main.cpp app/game.cpp app/game.hpp app/builder/window.cpp app/builder/window.hpp state/types/istate.hpp state/game.cpp state/game.hpp state/menu.cpp state/menu.hpp app/keyboard_keys.cpp app/keyboard_keys.hpp app/types/ikeys.hpp)
add_subdirectory(SFML)

target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window)