#include "object2D.h"

void Object2D::SetPosition(int x, int y) {
  _x = x;
  _y = y;
}

void Object2D::SetSize(int w, int h) {
  _w = w;
  _h = h;
}

void Object2D::SetVisibility(bool visible) {
  _isVisible = visible;
}

bool Object2D::IsVisible() {
  return _isVisible;
}
