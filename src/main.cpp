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
  constexpr std::size_t screenHeight = 680;
  constexpr std::size_t framesPerSecond{60};
  constexpr std::size_t msPerFrame{1000 / framesPerSecond};

  RendererOptions options;
  options.width = screenWidth;
  options.height = screenHeight;
  options.title = title;
  options.clearColor = Colors::DefaultBackground;

  Renderer renderer(options);
  Controller controller;

  Game game;
  game.Run(std::move(controller), std::move(renderer), msPerFrame);
  return 0;
}
