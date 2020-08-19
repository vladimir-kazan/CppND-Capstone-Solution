#include "./text.h"

Text::Text() {
  _setDefaults();
  cout << "Text()" << endl;
}

Text::~Text() {
  cout << "~Text() " << _text << endl;
  if (_font != nullptr)
    TTF_CloseFont(_font);
  //  SDL_DestroyTexture(texture);
}

void Text::Render(SDL_Renderer& renderer) {
  SDL_Surface* solid = TTF_RenderText_Solid(_font, _text.c_str(), _color);
  SDL_Texture* solidTexture = SDL_CreateTextureFromSurface(&renderer, solid);
  SDL_FreeSurface(solid);
  int x = _x;
  int y = _y;
  if (_horizontalAlign == HorizontalAlignment::centered) {
    x += (_w - _clipWidth) / 2;
  }
  if (_verticalAlign == VerticalAlignment::centered) {
    y += (_h - _clipHeight) / 2;
  }
  SDL_Rect solidRect{x, y, _w, _h};
  SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
  SDL_RenderCopy(&renderer, solidTexture, nullptr, &solidRect);
}

void Text::SetText(const string text) {
  _text = text;
  // to center it
  SDL_Surface* solid = TTF_RenderText_Solid(_font, _text.c_str(), _color);
  _clipWidth = solid->clip_rect.w;
  _clipHeight = solid->clip_rect.h;
  SDL_FreeSurface(solid);
}

void Text::SetHorizontalAlignment(HorizontalAlignment align) {
  _horizontalAlign = align;
}

void Text::SetVerticalAlignment(VerticalAlignment align) {
  _verticalAlign = align;
}

void Text::SetFontSize(int size) {
  if (_font != nullptr)
    TTF_CloseFont(_font);
  _font = TTF_OpenFont("fonts/sketchy.ttf", size);
}

void Text::_setDefaults() {
  _text = (char*)" ";
  _font = TTF_OpenFont("fonts/sketchy.ttf", 24);
  _color = Colors::White;
}
