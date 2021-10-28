#ifndef FLAPPY_BIRD_CONTROLLER_H
#define FLAPPY_BIRD_CONTROLLER_H

#include "decls.h"

#include <SDL2/SDL.h>

class Controller {
 public:
  virtual bool handleEvent(SDL_Event &) = 0;
};

#endif  // FLAPPY_BIRD_CONTROLLER_H
