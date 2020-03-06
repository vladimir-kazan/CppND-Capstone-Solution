#include "game.h"

#include <iostream>
#include <vector>

#include "objects/object2D.h"

Game::Game() {
  std::cout << "Game created" << std::endl;
  _objects.emplace_back(&_board);
}

Game::~Game() {
  std::cout << "Game destroyed" << std::endl;
}

void Game::Run(Controller&& controller,
               Renderer&& renderer,
               std::size_t frameDuration) {
  _board.SetPosition(10, 10);
  _board.SetSize(620, 620, 20);

  bool running = true;
  Uint32 title_timestamp = SDL_GetTicks();
  std::cout << "Running.." << std::endl;
  while (running) {
    controller.HandleInput(running);
    // update game state
    // render all elements
    renderer.Render(_objects);
  }
}
