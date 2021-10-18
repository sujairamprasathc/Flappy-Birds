#ifndef CONTROLLER_H
#define CONTROLLER_H 1

#include "decls.h"

#include <SDL2/SDL.h>

class Controller {
 public:
  virtual bool handleEvent(SDL_Event &) = 0;
};

#endif  // CONTROLLER_H
