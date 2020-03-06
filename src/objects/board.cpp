#include "board.h"

#include <iostream>

#include "../colors.h"
#include "SDL2/SDL.h"

Board::Board() {
  std::cout << "Board created" << std::endl;
}
Board::~Board() {
  std::cout << "~Board()" << std::endl;
}

void Board::SetSize(uint width, uint height, uint thickness) {
  _width = width;
  _height = height;
  _thickness = thickness;
}

void Board::SetPosition(uint x, uint y) {
  _x = x;
  _y = y;
}

void Board::Render(SDL_Renderer& renderer) {
  using Colors::Border;
  using Colors::BorderLight;

  // https://wiki.libsdl.org/SDL_Rect
  // SDL_SetRenderDrawColor(&renderer, BorderLight.r, BorderLight.g,
  // BorderLight.b,
  //                        BorderLight.a);
  // SDL_RenderDrawLine(&renderer, 20, 10, 20, 620);
  uint x1 = _x;
  uint x2 = _x + _width;
  uint y1 = _y;
  uint y2 = _y + _height;
  uint offset = _thickness / 2;

  SDL_SetRenderDrawColor(&renderer, Border.r, Border.g, Border.b, Border.a);
  SDL_RenderDrawLine(&renderer, x1, y1, x2, y1);  // top1
  SDL_RenderDrawLine(&renderer, x1 + offset, y1 + offset, x2 - offset, y1 + offset);  // top2
  SDL_RenderDrawLine(&renderer, x1, y2, x2, y2);  // bottom
  SDL_RenderDrawLine(&renderer, x1 + offset, y2 - offset, x2 - offset, y2 - offset);  // bottom
  SDL_RenderDrawLine(&renderer, x1, y1, x1, y2);  // left
  SDL_RenderDrawLine(&renderer, x1 + offset, y1 + offset, x1 + offset, y2 - offset);  // left
  SDL_RenderDrawLine(&renderer, x2, y1, x2, y2);  // right
  SDL_RenderDrawLine(&renderer, x2 - offset, y1 + offset, x2 - offset, y2 - offset);  // right

  uint stepX = (_width - _thickness) / 6;
  uint stepY = (_height - _thickness) / 6;

  x1 = x1 + offset;
  y1 = y1 + offset;
  y2 = y2 - offset;
  SDL_RenderDrawLine(&renderer, x1 + stepX, y1, x1 + stepX, y2);  // left
  SDL_RenderDrawLine(&renderer, x1 + stepX * 2, y1, x1 + stepX * 2,
                     y2);  // left
  SDL_RenderDrawLine(&renderer, x1 + stepX * 3, y1, x1 + stepX * 3,
                     y2);  // left
  SDL_RenderDrawLine(&renderer, x1 + stepX * 4, y1, x1 + stepX * 4,
                     y2);  // left
  SDL_RenderDrawLine(&renderer, x1 + stepX * 5, y1, x1 + stepX * 5,
                     y2);  // left
}
