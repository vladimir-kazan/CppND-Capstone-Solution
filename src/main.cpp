#include <iostream>
#include <string>

#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr char title[] = "Udacity Capstone Game";
  RendererOptions options;
  options.width = 640;
  options.height = 640;

  Renderer renderer(options);
  renderer.SetTitle(title);
  Controller controller;

  Game game;
  game.Run(std::move(controller), std::move(renderer));
  return 0;
}
