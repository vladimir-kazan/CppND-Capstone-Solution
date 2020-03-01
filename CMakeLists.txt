cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(NAME "game")
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

project(game)

file(GLOB SOURCES "src/*.cpp")
add_executable(${NAME} ${SOURCES})

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(${NAME} ${SDL2_LIBRARIES})
