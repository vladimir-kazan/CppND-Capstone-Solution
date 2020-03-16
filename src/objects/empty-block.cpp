#include "empty-block.h"

EmptyBlock::EmptyBlock() {
  std::cout << "EmptyBlock created" << std::endl;
}

EmptyBlock::EmptyBlock(uint x, uint y, uint width, uint height)
    : _width(width), _height(height) {
  _x = x;
  _y = y;
  std::cout << "EmptyBlock created" << std::endl;
}

EmptyBlock::~EmptyBlock() {
  std::cout << "~EmptyBlock()" << std::endl;
}

void EmptyBlock::Render(SDL_Renderer& renderer) {
  using Colors::Border;
  using Colors::BorderShade;
  uint offset = 10;
  uint x = _x + offset;
  uint y = _y + offset;
  uint width = _width - offset * 2;
  uint height = _height - offset * 2;
  SDL_SetRenderDrawColor(&renderer, Border.r, Border.g, Border.b, Border.a);
  SDL_RenderDrawLine(&renderer, x, y, x + width, y);   // top
  SDL_RenderDrawLine(&renderer, x, y, x, y + height);  // left
  // SDL_RenderDrawLine(&renderer, x + 1, y, x + 1, y + height); // left
  SDL_SetRenderDrawColor(&renderer, BorderShade.r, BorderShade.g, BorderShade.b,
                         BorderShade.a);
  SDL_RenderDrawLine(&renderer, x, y + height, x + width,
                     y + height);  // bottom
  SDL_RenderDrawLine(&renderer, x, y + height - 1, x + width,
                     y + height - 1);                                  // bottom
  SDL_RenderDrawLine(&renderer, x + width, y, x + width, y + height);  // right
  SDL_RenderDrawLine(&renderer, x + width - 1, y, x + width - 1,
                     y + height);  // right
}
