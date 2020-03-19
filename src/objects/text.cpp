#include "./text.h"

Text::Text() {
  _setDefaultFont();
  cout << "Text()" << endl;
}

Text::Text(string text) : _text(text) {
  _setDefaultFont();
  cout << "Text(string text)" << endl;
}

Text::~Text() {
  cout << "~Text()" << endl;
  if (_font != nullptr)
    TTF_CloseFont(_font);
  //  SDL_DestroyTexture(texture);
  //  SDL_FreeSurface(surface);
  //  TTF_CloseFont(font);
}

void Text::Render(SDL_Renderer& renderer) {
  SDL_Color white{255, 255, 255};
  SDL_Surface* solid = TTF_RenderText_Solid(_font, _text.c_str(), white);
  SDL_Texture* solidTexture = SDL_CreateTextureFromSurface(&renderer, solid);
  SDL_FreeSurface(solid);
  SDL_Rect solidRect{120, 10, 600, 40};
  // solidRect.x = 20;
  // solidRect.y = 10;
  // solidRect.w = 600;
  // solidRect.h = 40;
  SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
  SDL_RenderCopy(&renderer, solidTexture, nullptr, &solidRect);

  // SDL_Surface* surfaceMessage = TTF_RenderText_Solid(_font, _text.c_str(),
  // white); SDL_Texture* message = SDL_CreateTextureFromSurface(renderer,
  // surfaceMessage); SDL_Rect messageRect; messageRect.x = 20; messageRect.y =
  // 20; messageRect.w = 600; messageRect.h = 40; SDL_RenderCopy(renderer,
  // message, NULL, &messageRect);
}

void Text::SetText(string& text) {
  _text = text;
}

void Text::SetFont(TTF_Font* font) {
  _font = font;
}

void Text::_setDefaultFont() {
  // if (_font != nullptr)
  //   TTF_CloseFont(_font);
  _font = TTF_OpenFont("fonts/sketchy.ttf", 24);
  // TODO:
}
