#ifndef FLAPPY_BIRD_MODEL_H
#define FLAPPY_BIRD_MODEL_H

#include "decls.h"

#include <vector>

class Model {
  std::vector<View *> observerList;

 public:
  virtual ~Model() {}

  virtual void subscribe(View *);
  virtual void notify() const;
};

#endif  // FLAPPY_BIRD_MODEL_H
