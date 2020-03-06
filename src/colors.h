#ifndef COLORS_H
#define COLORS_H

#include "utils.h"

namespace Colors {

constexpr Color DefaultBackground = Color{0x00, 0x1E, 0x1E, 0xFF};
constexpr Color Red = Color{0x1E, 0x00, 0x00, 0xFF};
constexpr Color Border = Color{0xCC, 0xCC, 0xCC, 0x00};
constexpr Color BorderLight = Color{0x55, 0x55, 0x55, 0x00};
}  // namespace Colors

#endif
