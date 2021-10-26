#ifndef MODEL_H
#define MODEL_H 1

#include "decls.h"

class Model {
 public:
  Model();

  void subscribe(View *);
  void notify();
};

#endif  // MODEL_H
