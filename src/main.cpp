#include "renderer.h"
#include "game.h"
#include <iostream>

int main() {
  RendererOptions options;
  options.width = 640;
  options.height = 640;
  Renderer renderer(options);

  Game game;
  game.Run(std::move(renderer));
  return 0;
}
