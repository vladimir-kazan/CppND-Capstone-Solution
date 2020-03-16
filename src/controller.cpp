#include "controller.h"

Controller::Controller() {
  cout << "controller created" << endl;
}

Controller::~Controller() {
  cout << "controller destroyed" << endl;
}

void Controller::HandleInput(bool& running, GameCommand& command) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (e.key.keysym.sym) {
          case SDLK_LEFT:
            command.dX -= 1;
            break;
          case SDLK_RIGHT:
            command.dX += 1;
            break;
          case SDLK_UP:
            command.dY -= 1;
            break;
          case SDLK_DOWN:
            command.dY += 1;
            break;
          case SDLK_1:
          case SDLK_2:
          case SDLK_3:
          case SDLK_4:
          case SDLK_5:
          case SDLK_6:
          case SDLK_7:
          case SDLK_8:
          case SDLK_9:
          case SDLK_a:
          case SDLK_b:
          case SDLK_c:
          case SDLK_d:
          case SDLK_e:
            command.selection = (char)e.key.keysym.sym;
            break;
        }
        break;
      default:
        break;
    }
  }
}
