#ifndef OBJECTS_BOARD_H
#define OBJECTS_BOARD_H

#include "object2D.h"

class Board : public Object2D {
 public:
  Board();
  ~Board();
  void Render(SDL_Renderer& renderer) override;
  void SetSize(uint width, uint height, uint thickness);
  void SetPosition(uint x, uint y);

 private:
  uint _x = 0;
  uint _y = 0;
  uint _width = 0;
  uint _height = 0;
  uint _thickness = 0;
};

#endif
