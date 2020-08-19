#include "game.h"

Game::Game() : _grid(6, vector<int>(6, -1)), _levels_loaded{false}, _current_level{0} {
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
  //
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

    if (_current_level == 0 && _levels_loaded) {
      _current_level = 1;
      auto nextTitle = "Capstone project - level " + to_string(_current_level);
      SetTitle(nextTitle);
      // _initLevel(1);
    }

    frame_start = SDL_GetTicks();

    controller.HandleInput(running, command);
    _processInput(command);
    // render all elements
    renderer.PreRender();
    renderer.Render(_objects);
    renderer.Render(_cars);
    renderer.PostRender();

    frame_end = SDL_GetTicks();
    frame_duration = frame_end - frame_start;
    if (frame_duration < frameDuration) {
      SDL_Delay(frameDuration - frame_duration);
    }
  }
}

void Game::SetTitle(const string text) {
  _title.SetText(text);
}

void Game::SetCenteredText(const char* text) {
  _centeredText.SetText(text);
}

void Game::LoadLevelsAsync() {
  _levels_loaded = false;
  std::thread t(&Game::_loadLevels, this);
  t.detach();
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
  std::lock_guard<std::mutex> lck(_levels_mutex);

  _centeredText.SetVisibility(true);
  cout << "TODO: _loadLevels()" << endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  cout << "TODO: _loadLevels() = done." << endl;
  _centeredText.SetVisibility(false);
  _levels_loaded = true;
}
