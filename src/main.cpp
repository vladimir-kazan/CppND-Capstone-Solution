#include "renderer.h"
#include <iostream>

int main() {
  std::cout << "Hello World!"
            << "\n";
  RendererOptions options;
  options.width = 640;
  options.height = 640;
  Renderer renderer(options);
  return 0;
}
