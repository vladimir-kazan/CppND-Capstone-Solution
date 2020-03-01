#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include <string>

using std::size_t;
using std::string;

struct RendererOptions {
  size_t width;
  size_t height;
  string caption;
};

class Renderer {
public:
  Renderer(const RendererOptions options);
  ~Renderer();

private:
  SDL_Window *sdlWindow;
  SDL_Renderer *sdlRenderer;
  const size_t width;
  const size_t height;
  string caption;
};

#endif
