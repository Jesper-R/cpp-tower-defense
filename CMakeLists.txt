cmake_minimum_required(VERSION 3.28)
project(cpp-tower-defense LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
        GIT_SHALLOW ON)
FetchContent_MakeAvailable(nlohmann_json)

add_executable(cpp-tower-defense src/main.cpp
        src/Game.cpp
        src/Game.h
        src/map_code/GridCell.cpp
        src/map_code/GridCell.h
        src/map_code/GameMap.cpp
        src/map_code/GameMap.h
        src/map_code/CellBlock.cpp
        src/map_code/CellBlock.h
        src/wave_code/WaveManager.cpp
        src/wave_code/WaveManager.h
        src/Player.cpp
        src/Player.h
        src/UIManager.cpp
        src/UIManager.h
        src/enemy_code/Enemy.cpp
        src/enemy_code/Enemy.h
        src/enemy_code/BigEnemy.cpp
        src/enemy_code/BigEnemy.h
        src/enemy_code/BasicEnemy.cpp
        src/enemy_code/BasicEnemy.h
        src/GameObject.cpp
        src/GameObject.h
        src/wave_code/WaveData.cpp
        src/wave_code/WaveData.h
        src/TowerManager.cpp
        src/TowerManager.h
        src/tower_code/Tower.cpp
        src/tower_code/Tower.h
        src/tower_code/StoneThrower.cpp
        src/tower_code/StoneThrower.h
)
target_link_libraries(cpp-tower-defense PRIVATE sfml-graphics)
target_link_libraries(cpp-tower-defense PRIVATE nlohmann_json::nlohmann_json)
target_compile_features(cpp-tower-defense PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET cpp-tower-defense
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:cpp-tower-defense>
            VERBATIM)
endif()