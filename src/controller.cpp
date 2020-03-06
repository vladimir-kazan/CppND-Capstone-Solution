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
        switch (e.key.keysym.sym) {
          case SDLK_LEFT:
            std::cout << "left" << std::endl;
            break;
          case SDLK_RIGHT:
            std::cout << "right" << std::endl;
            break;
          case SDLK_UP:
            std::cout << "up" << std::endl;
            break;
          case SDLK_DOWN:
            std::cout << "down" << std::endl;
            break;
        }
        break;
      default:
        break;
    }
  }
}
