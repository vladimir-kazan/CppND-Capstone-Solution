#ifndef OBJECTS_OBJECT_2D_H
#define OBJECTS_OBJECT_2D_H

#include "SDL2/SDL.h"

class Object2D {
 public:
  virtual void Render(SDL_Renderer& renderer) = 0;
};

#endif
