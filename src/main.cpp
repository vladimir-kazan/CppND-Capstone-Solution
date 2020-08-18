#include <iostream>
#include <string>
#include <vector>

#include "colors.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr char title[] = "Udacity Capstone Game";
  constexpr int screenWidth = 640;
  constexpr int screenHeight = 680;
  constexpr int framesPerSecond{60};
  constexpr int msPerFrame{1000 / framesPerSecond};

  RendererOptions options;
  options.width = screenWidth;
  options.height = screenHeight;
  options.title = title;
  options.clearColor = Colors::DefaultBackground;

  Renderer renderer(options);
  Controller controller;

  Game game;
  game.LoadLevelsAsync();
  game.Run(std::move(controller), std::move(renderer), msPerFrame);
  return 0;
}
