#ifndef COLORS_H
#define COLORS_H

#include <SDL2/SDL_pixels.h>

namespace Colors {

constexpr SDL_Color DefaultBackground = {0x00, 0x3E, 0x3E};
constexpr SDL_Color Red = {0x1E, 0x00, 0x00};
constexpr SDL_Color Frame = {0x7A, 0x7A, 0x7A};
constexpr SDL_Color Border = {0xCC, 0xCC, 0xCC};
constexpr SDL_Color BorderLight = {0x55, 0x55, 0x55};
constexpr SDL_Color BorderShade = {0x07, 0x07, 0x07};
constexpr SDL_Color White = {0xFF, 0xFF, 0xFF};
}  // namespace Colors

#endif
