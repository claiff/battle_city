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

        ${RESOURCE_DIR}/manager.hpp
        ${RESOURCE_DIR}/texture_getter.cpp
        ${RESOURCE_DIR}/texture_getter.hpp

        ${RESOURCE_DIR}/builder/ally_tank.cpp
        ${RESOURCE_DIR}/builder/ally_tank.hpp
        ${RESOURCE_DIR}/builder/landscape.cpp
        ${RESOURCE_DIR}/builder/landscape.hpp
        ${RESOURCE_DIR}/builder/border.cpp
        ${RESOURCE_DIR}/builder/border.hpp
        ${RESOURCE_DIR}/builder/landscape.cpp
        ${RESOURCE_DIR}/builder/landscape.hpp
        ${RESOURCE_DIR}/builder/border.cpp
        ${RESOURCE_DIR}/builder/border.hpp

        ${RESOURCE_DIR}/parser/ini.cpp
        ${RESOURCE_DIR}/parser/ini.hpp
        ${RESOURCE_DIR}/parser/landscape.cpp
        ${RESOURCE_DIR}/parser/landscape.hpp

        ${RESOURCE_DIR}/reader/ini.cpp
        ${RESOURCE_DIR}/reader/ini.hpp
        ${RESOURCE_DIR}/reader/landscape.cpp
        ${RESOURCE_DIR}/reader/landscape.hpp

        ${RESOURCE_DIR}/types/ibuilder.hpp
        ${RESOURCE_DIR}/types/iparser.hpp

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
        ${ENTITY_DIR}/types/itank_entity.hpp
        ${ENTITY_DIR}/builder/player.cpp
        ${ENTITY_DIR}/builder/player.hpp
        ${ENTITY_DIR}/builder/projectile.cpp
        ${ENTITY_DIR}/builder/projectile.hpp
        ${ENTITY_DIR}/animate_rectangle_shape.cpp
        ${ENTITY_DIR}/animate_rectangle_shape.hpp
        ${ENTITY_DIR}/projectile.cpp
        ${ENTITY_DIR}/projectile.hpp

        ${UTILS_DIR}/timer_policy.cpp
        ${UTILS_DIR}/timer_policy.hpp
        ${UTILS_DIR}/types/ipolicy.hpp
        ${UTILS_DIR}/types/idecorator.hpp
        ${UTILS_DIR}/types/registrator.hpp
        ${UTILS_DIR}/consistent_registrator.hpp
        ${UTILS_DIR}/direction_helper.cpp
        ${UTILS_DIR}/direction_helper.hpp

        layer/landscape.cpp layer/landscape.hpp resource/reader/landscape.cpp resource/reader/landscape.hpp resource/parser/landscape.cpp resource/parser/landscape.hpp resource/types/iparser.hpp)
add_subdirectory(SFML)

target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window)