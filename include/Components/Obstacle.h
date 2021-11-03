#ifndef FLAPPY_BIRD_COMPONENTS_OBSTACLE_H
#define FLAPPY_BIRD_COMPONENTS_OBSTACLE_H

#include <utility>
#include <vector>

#include "Drawable.h"

class Obstacle : public Drawable {
  float left_x{};
  float top_y{};
  float right_x{};
  float bottom_y{};

  unsigned type;

  void init();
  void reset();

 public:
  explicit Obstacle(unsigned);

  void draw() const override;

  bool isPointInside(std::pair<float, float>) const;
  std::vector<std::pair<float, float>> getBoundingBox() const;

  void moveLeftBy(float);
};

#endif  // FLAPPY_BIRD_COMPONENTS_OBSTACLE_H
