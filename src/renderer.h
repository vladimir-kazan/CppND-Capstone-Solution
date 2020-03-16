#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <string>
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "objects/object2D.h"
#include "utils.h"

using std::size_t;
using std::string;

struct RendererOptions {
  size_t width;
  size_t height;
  const char* title;
  Color clearColor;
};

class Renderer {
 public:
  Renderer(const RendererOptions options);
  ~Renderer();
  void SetTitle(const char* title);
  void SetTitle(string& title);
  void Render(const std::vector<Object2D*>& objects);

 private:
  SDL_Window* _sdlWindow;
  SDL_Renderer* _sdlRenderer;
  const size_t _width;
  const size_t _height;
  const char* _title;
  Color _clearColor;
  void _updateTitle();
};

#endif
