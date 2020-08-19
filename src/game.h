#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <future>
#include <thread>
#include <vector>

#include "./utils.h"
#include "controller.h"
#include "levels/level.h"
#include "objects/board.h"
#include "objects/empty-block.h"
#include "objects/object2D.h"
#include "objects/car.h"
#include "objects/text.h"
#include "renderer.h"

using std::cout;
using std::endl;
using std::size_t;
using std::vector;
using std::string;
using std::to_string;

class Game {
 public:
  Game();
  ~Game();
  void Run(Controller&& controller, Renderer&& renderer, size_t frameDuration);
  void SetTitle(const string text);
  void SetCenteredText(const char* text);
  void LoadLevelsAsync();

 private:
  Board _board{};
  vector<Object2D*> _objects;
  vector<Object2D*> _cars;
  vector<vector<int>> _grid;
  void _processInput(GameCommand& command);
  Text _title;
  Text _centeredText;
  void _loadLevels();
  vector<Level*> _levels;
  bool _levels_loaded;
  std::mutex _levels_mutex;
  int _current_level;
};

#endif
