#ifndef FLAPPY_BIRD_COMPONENTS_BUILDING_H
#define FLAPPY_BIRD_COMPONENTS_BUILDING_H

#include <utility>

#include "Drawable.h"

class Building : public Drawable {
  std::pair<float, float> top_left;
  std::pair<float, float> bottom_right;

 public:
  Building(float height, float left, float right);

  void draw() const override;

  void setTopLeft(std::pair<float, float>);
  void setBottomRight(std::pair<float, float>);

  void moveLeft();
};

#endif  // FLAPPY_BIRD_COMPONENTS_BUILDING_H
