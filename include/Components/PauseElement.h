#ifndef FLAPPY_BIRD_COMPONENTS_PAUSE_ELEMENT_H
#define FLAPPY_BIRD_COMPONENTS_PAUSE_ELEMENT_H

#include "Drawable.h"

class PauseElement : public Drawable {
 public:
  ~PauseElement() = default;

  void draw() const override;
};

#endif  // FLAPPY_BIRD_COMPONENTS_PAUSE_ELEMENT_H
