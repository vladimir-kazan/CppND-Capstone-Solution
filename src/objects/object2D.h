#ifndef OBJECTS_OBJECT_2D_H
#define OBJECTS_OBJECT_2D_H

#include <SDL2/SDL.h>

class Object2D {
 public:
  virtual void Render(SDL_Renderer& renderer) = 0;
  void SetPosition(int x, int y);
  void SetSize(int w, int h);
  void SetVisibility(bool visible);
  bool IsVisible();

 protected:
  int _x;
  int _y;
  int _w;
  int _h;
  bool _isVisible = true;
};

#endif
