#ifndef GAME_H
#define GAME_H

#include <vector>

#include "controller.h"
#include "objects/board.h"
#include "renderer.h"

class Game {
 public:
  Game();
  ~Game();
  void Run(Controller&& controller,
           Renderer&& renderer,
           std::size_t frameDuration);

 private:
  Board _board{};
  std::vector<Object2D*> _objects;
};

#endif
