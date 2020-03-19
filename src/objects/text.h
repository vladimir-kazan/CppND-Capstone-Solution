#ifndef OBJECTS_TEXT_H
#define OBJECTS_TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>

#include "../colors.h"
#include "object2D.h"

using std::cout;
using std::endl;
using std::string;

enum class HorizontalAlignment { none, centered };

enum class VerticalAlignment { none, centered };

class Text : public Object2D {
 public:
  Text();
  Text(char* text);
  ~Text();
  void Render(SDL_Renderer& renderer) override;
  void SetText(const char* text);
  void SetHorizontalAlignment(HorizontalAlignment align);
  void SetVerticalAlignment(VerticalAlignment align);
  void SetFontSize(int size);

 private:
  const char* _text;
  TTF_Font* _font = nullptr;
  SDL_Color _color;
  SDL_Texture* _tex = nullptr;
  void _setDefaults();
  int _clipWidth;
  int _clipHeight;
  HorizontalAlignment _horizontalAlign = HorizontalAlignment::none;
  VerticalAlignment _verticalAlign = VerticalAlignment::none;
};

#endif
