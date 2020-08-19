#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include <vector>

#include "objects/object2D.h"
#include "utils.h"

using std::size_t;
using std::string;

struct RendererOptions {
  size_t width;
  size_t height;
  const char* title;
  SDL_Color clearColor;
};

class Renderer {
 public:
  Renderer(const RendererOptions options);
  ~Renderer();
  void SetTitle(const char* title);
  void SetTitle(string& title);
  void PreRender();
  void Render(const std::vector<Object2D*>& objects);
  void PostRender();

 private:
  SDL_Window* _sdlWindow;
  SDL_Renderer* _sdlRenderer;
  const size_t _width;
  const size_t _height;
  const char* _title;
  SDL_Color _clearColor;
  void _updateTitle();
};

#endif
