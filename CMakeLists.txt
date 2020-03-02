cmake_minimum_required(VERSION 3.7)

project(game)

set(NAME "game")
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
add_definitions(-std=c++17)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2-ttf CONFIG REQUIRED)
find_package(freetype CONFIG REQUIRED)
find_package(libpng CONFIG REQUIRED)

file(GLOB SOURCES "src/*.cpp")
add_executable(${NAME} ${SOURCES})

target_link_libraries(${NAME} PRIVATE SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(${NAME} PRIVATE SDL2::SDL2_ttf)
target_link_libraries(${NAME} PRIVATE freetype)
target_link_libraries(${NAME} PRIVATE png_static)

# Copy files from source directory to destination directory
macro(configure_files srcDir destDir)
  message(STATUS "Configuring directory ${destDir}")
  make_directory(${destDir})

  file(GLOB templateFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/${srcDir} "${CMAKE_CURRENT_SOURCE_DIR}/${srcDir}/*")
  foreach(templateFile ${templateFiles})
    set(srcTemplatePath ${srcDir}/${templateFile})
    if(NOT IS_DIRECTORY ${srcTemplatePath})
      message(STATUS "Configuring file ${templateFile}")
      configure_file(${srcTemplatePath} ${destDir}/${templateFile} COPYONLY)
    endif(NOT IS_DIRECTORY ${srcTemplatePath})
  endforeach(templateFile)
endmacro(configure_files)

configure_files(levels levels)
