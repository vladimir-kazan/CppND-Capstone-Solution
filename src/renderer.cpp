#include "renderer.h"

Renderer::Renderer(RendererOptions options)
    : _width(options.width),
      _height(options.height),
      _title(options.title),
      _clearColor(options.clearColor) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  if (TTF_Init() != 0) {
    std::cerr << "SDL TTF could not initialize.\n";
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

  SDL_RenderSetLogicalSize(_sdlRenderer, _width, _height);
  // SDL_SetRenderDrawBlendMode(_sdlRenderer, SDL_BLENDMODE_BLEND);
  _updateTitle();

  std::cout << "Renderer created" << std::endl;
}

Renderer::~Renderer() {
  SDL_DestroyWindow(_sdlWindow);
  SDL_Quit();
  TTF_Quit();
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

void Renderer::Render(const std::vector<Object2D*>& objects) {
  // Clear screen
  SDL_SetRenderDrawColor(_sdlRenderer, _clearColor.r, _clearColor.g,
                         _clearColor.b, _clearColor.a);
  SDL_RenderClear(_sdlRenderer);

  for (auto obj : objects) {
    if (obj->IsVisible())
      obj->Render(*_sdlRenderer);
  }

  SDL_RenderPresent(_sdlRenderer);
}

// private
void Renderer::_updateTitle() {
  if (_sdlWindow != nullptr) {
    SDL_SetWindowTitle(_sdlWindow, _title);
  }
}
