#ifndef FLAPPY_BIRD_COMPONENTS_OBSTACLE_H
#define FLAPPY_BIRD_COMPONENTS_OBSTACLE_H

#include <utility>
#include <vector>

class Obstacle {
  float left_x{};
  float top_y{};
  float right_x{};
  float bottom_y{};

  unsigned type;

  void init();
  void reset();

 public:
  Obstacle(unsigned);

  void draw() const;

  float getHeight() const;
  void setHeight(float);

  bool isPointInside(std::pair<float, float>) const;
  std::vector<std::pair<float, float>> getBoundingBox() const;

  void moveLeftBy(float);
};

#endif  // FLAPPY_BIRD_COMPONENTS_OBSTACLE_H
