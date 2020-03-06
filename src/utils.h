#ifndef UTILS_H
#define UTILS_H

struct Color {
 public:
  uint r;
  uint g;
  uint b;
  uint a;
  Color() : r(0), g(0), b(0), a(0){};
  constexpr Color(const uint _r, const uint _g, const uint _b, const uint _a)
      : r(_r), g(_g), b(_b), a(_a){};
};

#endif
