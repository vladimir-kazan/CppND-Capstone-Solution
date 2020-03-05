#ifndef OBJECTS_BOARD_H
#define OBJECTS_BOARD_H

#include "object2D.h"

class Board : public Object2D {
 public:
  Board();
  ~Board();
  void Render(SDL_Renderer& renderer) override;

 private:
  uint _width;
  uint _height;
};

#endif
