#include "controller.h"

#include <iostream>

#include "SDL2/SDL.h"

Controller::Controller() {
  std::cout << "controller created" << std::endl;
}

Controller::~Controller() {
  std::cout << "controller destroyed" << std::endl;
}

void Controller::HandleInput(bool& running) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    }
  }
}
