#ifndef EMPTY_BLOCK_H
#define EMPTY_BLOCK_H

#include <iostream>

#include "../colors.h"
#include "object2D.h"

class EmptyBlock : public Object2D {
 public:
  EmptyBlock();
  EmptyBlock(uint x, uint y, uint width, uint height);
  ~EmptyBlock();
  void Render(SDL_Renderer& renderer) override;

 private:
  uint _width = 0;
  uint _height = 0;
};

#endif
