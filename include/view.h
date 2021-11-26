#ifndef FLAPPY_BIRD_VIEW_H
#define FLAPPY_BIRD_VIEW_H

#include <SDL2/SDL.h>

#include "decls.h"

#include "controller.h"
#include "model.h"

class View {
 public:
  virtual ~View() = default;

  virtual void render() = 0;
};

#endif  // FLAPPY_BIRD_VIEW_H
