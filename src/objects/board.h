#ifndef OBJECTS_BOARD_H
#define OBJECTS_BOARD_H

#include <SDL2/SDL.h>

#include <iostream>

#include "../colors.h"
#include "object2D.h"

class Board : public Object2D {
 public:
  Board();
  ~Board();
  void Render(SDL_Renderer& renderer) override;
  void SetSize(uint width, uint height, uint thickness);

 private:
  uint _width = 0;
  uint _height = 0;
  uint _thickness = 0;
};

#endif
