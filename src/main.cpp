#include <iostream>
#include <string>
#include <vector>

#include "colors.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr char title[] = "Udacity Capstone Game";
  constexpr std::size_t screenWidth = 640;
  constexpr std::size_t screenHeight = 640;
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

  RendererOptions options;
  options.width = screenWidth;
  options.height = screenHeight;
  options.title = title;
  options.clearColor = Colors::DefaultBackground;

  Renderer renderer(options);
  Controller controller;

  Game game;
  game.Run(std::move(controller), std::move(renderer), kMsPerFrame);
  return 0;
}
