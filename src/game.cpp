#include "game.h"

Game::Game() : _grid(6, vector<int>(6, -1)) {
  cout << "Game created" << endl;

  _board.SetPosition(10, 50);
  _board.SetSize(620, 620, 20);
  _objects.emplace_back(&_board);
}

Game::~Game() {
  cout << "~Game()" << endl;
}

void Game::Run(Controller&& controller,
               Renderer&& renderer,
               size_t frameDuration) {
  Text text = Text{std::string("Hello world")};
  _objects.emplace_back(&text);

  auto empty = EmptyBlock{20, 60, 100, 100};
  _objects.emplace_back(&empty);

  bool running = true;
  GameCommand command;
  Uint32 title_timestamp = SDL_GetTicks();
  cout << "Running.." << endl;
  while (running) {
    controller.HandleInput(running, command);
    if (command.dX != 0) {
      cout << "dx: " << command.dX << endl;
      command.dX = 0;
    }
    if (command.dY != 0) {
      cout << "dy: " << command.dY << endl;
      command.dY = 0;
    }
    if (command.selection != 0) {
      cout << "selection: " << command.selection << endl;
      command.selection = (char)0;
    }
    // update game state
    // render all elements
    renderer.Render(_objects);
  }
}
