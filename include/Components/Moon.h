#ifndef FLAPPY_BIRD_COMPONENTS_MOON_H
#define FLAPPY_BIRD_COMPONENTS_MOON_H

#include "Drawable.h"

class Moon : public Drawable {
 public:
  ~Moon() = default;

  void draw() const override;
};

#endif  // FLAPPY_BIRD_COMPONENTS_MOON_H
