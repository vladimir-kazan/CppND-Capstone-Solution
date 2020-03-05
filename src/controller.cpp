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
    switch (e.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:

        break;
      default:
        break;
    }
  }
}
