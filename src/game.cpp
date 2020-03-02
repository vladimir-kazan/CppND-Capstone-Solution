#include <iostream>
#include "game.h"

Game::Game() {

}

Game::~Game() {
  std::cout << "Game destroyed" << std::endl;
}


void Game::Run(Renderer&& renderer) {
  std::cout << "Running.." << std::endl;
}
