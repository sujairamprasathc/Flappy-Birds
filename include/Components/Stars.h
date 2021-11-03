#ifndef FLAPPY_BIRD_COMPONENTS_STARS_H
#define FLAPPY_BIRD_COMPONENTS_STARS_H

#include "Drawable.h"

class Stars : public Drawable {
 public:
  ~Stars() = default;

  void draw() const override;
};

#endif  // FLAPPY_BIRD_COMPONENTS_STARS_H
