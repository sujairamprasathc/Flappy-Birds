#ifndef FLAPPY_BIRD_MODEL_H
#define FLAPPY_BIRD_MODEL_H

#include "decls.h"

class Model {
 public:
  Model();

  void subscribe(View *);
  void notify();
};

#endif  // FLAPPY_BIRD_MODEL_H
