# add_executable(rpg
#     src/main.cpp
#     ${SOURCES}
# )

cmake_minimum_required(VERSION 3.16)
project(RPG_POO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE GAME_SOURCES
    src/*.cpp
)

add_library(rpg_lib ${GAME_SOURCES})

add_executable(rpg main.cpp)
target_link_libraries(rpg rpg_lib)

add_executable(test_objets tests/test_objets.cpp)
target_link_libraries(test_objets rpg_lib)

add_executable(test_entities tests/test_entities.cpp)
target_link_libraries(test_entities rpg_lib)

add_executable(test_marchand tests/test_marchand.cpp)
target_link_libraries(test_marchand rpg_lib)

add_executable(test_plateau tests/test_plateau.cpp)
target_link_libraries(test_plateau rpg_lib)
