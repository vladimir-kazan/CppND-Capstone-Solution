cmake_minimum_required(VERSION 3.7)

project(game)

set(NAME "game")
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

add_definitions(-std=c++17)

# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# # list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
# message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIR} src)
# message(STATUS "SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR}")

find_package(SDL2 CONFIG REQUIRED)
message(STATUS "SDL2_FOUND ${SDL2_FOUND}")
message(STATUS "SDL2_INCLUDES ${SDL2_INCLUDES}")
message(STATUS "SDL2_LIBRARIES ${SDL2_LIBRARIES}")
message(STATUS "SDL2_DEFINITIONS ${SDL2_DEFINITIONS}")
message(STATUS "SLD2_CONFIG ${SLD2_CONFIG}")
message(STATUS "SLD2_VERSION ${SLD2_VERSION}")

find_package(SDL2-ttf CONFIG REQUIRED)
find_package(freetype CONFIG REQUIRED)
find_package(libpng CONFIG REQUIRED)




# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# find_package(SDL2_ttf REQUIRED)
# include_directories(${SDL2_TTF_INCLUDE_DIR} src)
# message(STATUS "SDL2_TTF_INCLUDE_DIR: ${SDL2_TTF_INCLUDE_DIR}")


file(GLOB SOURCES "src/*.cpp")
add_executable(${NAME} ${SOURCES})

target_link_libraries(${NAME} PRIVATE SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(${NAME} PRIVATE SDL2::SDL2_ttf)
target_link_libraries(${NAME} PRIVATE freetype)
target_link_libraries(${NAME} PRIVATE png_static)


# string(STRIP "${SDL2_LIBRARY}" SDL2_LIBRARY)
# target_link_libraries(${NAME} ${SDL2_LIBRARY})

# string(STRIP "${SDL2_TTF_LIBRARIES}" SDL2_TTF_LIBRARIES)
# target_link_libraries(${NAME} ${SDL2_TTF_LIBRARIES})



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
