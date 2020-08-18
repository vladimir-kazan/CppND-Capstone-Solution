#include "game.h"

Game::Game() : _grid(6, vector<int>(6, -1)) {
  cout << "Game created" << endl;
  // screen 640 x 680
  _title.SetPosition(0, 0);
  _title.SetSize(640, 50);
  _title.SetHorizontalAlignment(HorizontalAlignment::centered);
  _title.SetVerticalAlignment(VerticalAlignment::centered);

  _centeredText.SetPosition(10, 50);
  _centeredText.SetSize(620, 620);
  _centeredText.SetFontSize(48);
  _centeredText.SetHorizontalAlignment(HorizontalAlignment::centered);
  _centeredText.SetVerticalAlignment(VerticalAlignment::centered);

  _board.SetPosition(10, 50);
  _board.SetSize(620, 620, 20);
  // Create objects to render, keep the order
  _objects.emplace_back(&_title);
  _objects.emplace_back(&_board);
  _objects.emplace_back(&_centeredText);
}

Game::~Game() {
  cout << "~Game()" << endl;
}

// auto empty = EmptyBlock{20, 60, 100, 100};
// _objects.emplace_back(&empty);
void Game::Run(Controller&& controller,
               Renderer&& renderer,
               size_t frameDuration) {
  SetTitle("Capstone project");
  SetCenteredText("Loading levels...");

  bool running = true;
  GameCommand command;
  Uint32 title_timestamp = SDL_GetTicks();
  cout << "Running.." << endl;

  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  while (running) {
    frame_start = SDL_GetTicks();

    controller.HandleInput(running, command);
    _processInput(command);
    // render all elements
    renderer.Render(_objects);

    frame_end = SDL_GetTicks();
    frame_duration = frame_end - frame_start;
    if (frame_duration < frameDuration) {
      SDL_Delay(frameDuration - frame_duration);
    }
  }
}

void Game::SetTitle(const char* text) {
  _title.SetText(text);
  // center it
}

void Game::SetCenteredText(const char* text) {
  _centeredText.SetText(text);
}

void Game::LoadLevelsAsync() {
  _loadLevels();
}

// privates

void Game::_processInput(GameCommand& command) {
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
}

void Game::_loadLevels() {
  // TODO async here
  cout << "TODO: _loadLevels()" << endl;
  _centeredText.SetVisibility(true);
}
