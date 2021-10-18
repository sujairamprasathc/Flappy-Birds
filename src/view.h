#ifndef VIEW_H
#define VIEW_H 1

#include <SDL2/SDL.h>

#include "decls.h"

#include "model.h"
#include "controller.h"

class View {
 public:
  virtual void render() = 0;
};

#endif  // VIEW_H
