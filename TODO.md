vspkg

./vcpkg install sdl2
./vcpkg install sdl2-ttf

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(main PRIVATE SDL2::SDL2main SDL2::SDL2-static)

find_package(sdl2-ttf CONFIG REQUIRED)
target_link_libraries(main PRIVATE SDL2::SDL2_ttf)
