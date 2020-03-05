#include "board.h"

#include <iostream>

#include "SDL2/SDL.h"

Board::Board() {
  std::cout << "Board created" << std::endl;
}
Board::~Board() {
  std::cout << "~Board()" << std::endl;
}

void Board::Render(SDL_Renderer& renderer) {
  // frame
  SDL_Rect block;
  block.w = 640 - 20;
  block.h = 640 - 20;
  block.x = 10;
  block.y = 10;
  // SDL_MapRGB
  // https://wiki.libsdl.org/SDL_Rect
  SDL_SetRenderDrawColor(&renderer, 0xCC, 0xCC, 0xCC, 0x00);
  SDL_RenderDrawRect(&renderer, &block);
}
