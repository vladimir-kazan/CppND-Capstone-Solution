#ifndef OBJECTS_CAR_H
#define OBJECTS_CAR_H

#include <iostream>

#include "object2D.h"

using std::cout;
using std::endl;

class Car : public Object2D {
 public:
  Car();
  ~Car();
  void Render(SDL_Renderer& renderer) override;


};

#endif
