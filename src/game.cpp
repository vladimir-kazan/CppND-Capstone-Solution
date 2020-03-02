#include "game.h"

#include <iostream>
#include <vector>

Game::Game() {
  std::cout << "Game created" << std::endl;
}

Game::~Game() {
  std::cout << "Game destroyed" << std::endl;
}

void Game::Run(Controller&& controller, Renderer&& renderer, std::size_t frameDuration) {
  bool running = true;
  Uint32 title_timestamp = SDL_GetTicks();
  std::cout << "Running.." << std::endl;
  while (running) {
    controller.HandleInput(running);
    // update game state
    // render all elements
  }
}
