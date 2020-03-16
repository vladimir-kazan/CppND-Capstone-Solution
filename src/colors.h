#ifndef COLORS_H
#define COLORS_H

#include "utils.h"

namespace Colors {

constexpr Color DefaultBackground = Color{0x00, 0x3E, 0x3E, 0xFF};
constexpr Color Red = Color{0x1E, 0x00, 0x00, 0xFF};
constexpr Color Frame = Color{0x7A, 0x7A, 0x7A, 0x00};
constexpr Color Border = Color{0xCC, 0xCC, 0xCC, 0x00};
constexpr Color BorderLight = Color{0x55, 0x55, 0x55, 0x00};
constexpr Color BorderShade = Color{0x07, 0x07, 0x07, 0x00};
}  // namespace Colors

#endif
