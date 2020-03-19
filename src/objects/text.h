#ifndef OBJECTS_TEXT_H
#define OBJECTS_TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>

#include "object2D.h"

using std::cout;
using std::endl;
using std::string;

class Text : public Object2D {
 public:
  Text();
  Text(string text);
  ~Text();
  void Render(SDL_Renderer& renderer) override;
  void SetText(string& text);
  void SetFont(TTF_Font* font);

 private:
  string _text;
  TTF_Font* _font;
  void _setDefaultFont();
};

#endif
