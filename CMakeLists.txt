cmake_minimum_required(VERSION 3.22)
project(battle_city)

set(CMAKE_CXX_STANDARD 23)
set(APP_DIR app)
set(RESOURCE_DIR resource)
set(STATE_DIR state)
set(LAYER_DIR layer)
set(ENTITY_DIR entity)
set(UTILS_DIR utils)

add_executable(${PROJECT_NAME}
        main.cpp
        ${APP_DIR}/game.cpp
        ${APP_DIR}/game.hpp
        ${APP_DIR}/builder/window.cpp
        ${APP_DIR}/builder/window.hpp
        ${APP_DIR}/keyboard_keys.cpp
        ${APP_DIR}/keyboard_keys.hpp
        ${APP_DIR}/types/ikeys.hpp

        ${RESOURCE_DIR}/manager.cpp
        ${RESOURCE_DIR}/manager.hpp
        ${RESOURCE_DIR}/ini_reader.cpp
        ${RESOURCE_DIR}/ini_reader.hpp
        ${RESOURCE_DIR}/parser.cpp
        ${RESOURCE_DIR}/parser.hpp
        ${RESOURCE_DIR}/builder/sprite.cpp
        ${RESOURCE_DIR}/builder/sprite.hpp

        ${STATE_DIR}/types/istate.hpp
        ${STATE_DIR}/game.cpp
        ${STATE_DIR}/game.hpp
        ${STATE_DIR}/menu.cpp
        ${STATE_DIR}/menu.hpp

        ${LAYER_DIR}/types/ilayer.hpp
        ${LAYER_DIR}/background.cpp
        ${LAYER_DIR}/background.hpp
        ${LAYER_DIR}/border.cpp
        ${LAYER_DIR}/border.hpp

        ${ENTITY_DIR}/player.cpp
        ${ENTITY_DIR}/player.hpp
        ${ENTITY_DIR}/types/ientity.hpp
        ${ENTITY_DIR}/player_builder.cpp
        ${ENTITY_DIR}/player_builder.hpp
        ${ENTITY_DIR}/animate_rectangle_shape.cpp
        ${ENTITY_DIR}/animate_rectangle_shape.hpp

        ${UTILS_DIR}/timer_policy.cpp
        ${UTILS_DIR}/timer_policy.hpp
        ${UTILS_DIR}/types/ipolicy.hpp
        ${UTILS_DIR}/types/idecorator.hpp
        ${UTILS_DIR}/types/registrator.hpp
        ${UTILS_DIR}/consistent_registrator.hpp
)
add_subdirectory(SFML)

target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window)