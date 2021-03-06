#include "board.h"

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

void Board::Render(SDL_Renderer& renderer) {
  using Colors::BorderLight;
  using Colors::Frame;

  // https://wiki.libsdl.org/SDL_Rect
  // SDL_SetRenderDrawColor(&renderer, BorderLight.r, BorderLight.g,
  // BorderLight.b,
  //                        BorderLight.a);
  // SDL_RenderDrawLine(&renderer, 20, 10, 20, 620);
  uint x1 = _x;
  uint y1 = _y;

  uint x2 = _x + _width;
  uint y2 = _y + _height;
  uint offset = _thickness / 2;

  SDL_SetRenderDrawColor(&renderer, Frame.r, Frame.g, Frame.b, Frame.a);
  SDL_RenderDrawLine(&renderer, x1, y1, x2, y1);  // top1
  SDL_RenderDrawLine(&renderer, x1 + offset, y1 + offset, x2 - offset,
                     y1 + offset);                // top2
  SDL_RenderDrawLine(&renderer, x1, y2, x2, y2);  // bottom
  SDL_RenderDrawLine(&renderer, x1 + offset, y2 - offset, x2 - offset,
                     y2 - offset);                // bottom
  SDL_RenderDrawLine(&renderer, x1, y1, x1, y2);  // left
  SDL_RenderDrawLine(&renderer, x1 + offset, y1 + offset, x1 + offset,
                     y2 - offset);  // left

  // right
  uint blockH = _height / 6;
  SDL_RenderDrawLine(&renderer, x2, y1, x2, y2 - blockH * 4);
  SDL_RenderDrawLine(&renderer, x2 - offset, y1 + offset, x2 - offset,
                     y2 - blockH * 4);
  SDL_RenderDrawLine(&renderer, x2 - offset, y2 - blockH * 4, x2,
                     y2 - blockH * 4);

  SDL_RenderDrawLine(&renderer, x2 - offset, y2 - blockH * 3, x2,
                     y2 - blockH * 3);
  SDL_RenderDrawLine(&renderer, x2 - offset, y2 - blockH * 3, x2 - offset,
                     y2 - offset);
  SDL_RenderDrawLine(&renderer, x2, y2 - blockH * 3, x2, y2);
}
