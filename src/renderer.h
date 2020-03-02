#ifndef RENDERER_H
#define RENDERER_H

#include <string>

#include "SDL2/SDL.h"

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
  void SetTitle(const char* title);
  void SetTitle(string& title);
  void Render();

 private:
  SDL_Window* _sdlWindow;
  SDL_Renderer* _sdlRenderer;
  const size_t _width;
  const size_t _height;
  const char* _title;
};

#endif
