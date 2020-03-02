#include <iostream>
#include <string>

#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr char title[] = "Udacity Capstone Game";
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

  RendererOptions options;
  options.width = 640;
  options.height = 640;
  options.title = title;

  Renderer renderer(options);
  // renderer.SetTitle(title);
  Controller controller;

  Game game;
  game.Run(std::move(controller), std::move(renderer), kMsPerFrame);
  return 0;
}
