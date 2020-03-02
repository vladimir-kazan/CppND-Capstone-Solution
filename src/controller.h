#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
 public:
  Controller();
  ~Controller();
  void HandleInput(bool& running);
};
#endif
