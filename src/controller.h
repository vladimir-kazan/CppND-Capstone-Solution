#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>

#include <iostream>

#include "./utils.h"

using std::cout;
using std::endl;

class Controller {
 public:
  Controller();
  ~Controller();
  void HandleInput(bool& running, GameCommand& command);
};
#endif
