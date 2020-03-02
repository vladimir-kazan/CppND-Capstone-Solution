#include "renderer.h"

#include <iostream>

#include "SDL2/SDL_ttf.h"

Renderer::Renderer(RendererOptions options)
    : _width(options.width), _height(options.height), _title(options.title) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  // Create Window
  _sdlWindow = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, _width, _height,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);

  if (nullptr == _sdlWindow) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  _sdlRenderer = SDL_CreateRenderer(_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == _sdlRenderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  if (TTF_Init() != 0) {
    std::cerr << "SDL could not initialize.\n";
  }
  _updateTitle();

  std::cout << "Renderer created" << std::endl;
}

Renderer::~Renderer() {
  SDL_DestroyWindow(_sdlWindow);
  SDL_Quit();
  std::cout << "Renderer destroyed" << std::endl;
}

void Renderer::SetTitle(const char* title) {
  _title = title;
  _updateTitle();
}
void Renderer::SetTitle(string& title) {
  _title = title.c_str();
  _updateTitle();
}

void Renderer::Render() {
  // Clear screen
  SDL_SetRenderDrawColor(_sdlRenderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(_sdlRenderer);
}

// private
void Renderer::_updateTitle() {
  if (_sdlWindow != nullptr) {
    SDL_SetWindowTitle(_sdlWindow, _title);
  }
}
