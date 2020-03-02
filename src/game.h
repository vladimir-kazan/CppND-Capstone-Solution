#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "renderer.h"

class Game {
 public:
  Game();
  ~Game();
  void Run(Controller&& controller, Renderer&& renderer);

 private:
};

#endif
