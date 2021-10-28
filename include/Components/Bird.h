#ifndef FLAPPY_BIRD_COMPONENTS_BIRD_H
#define FLAPPY_BIRD_COMPONENTS_BIRD_H

#include <utility>
#include <vector>

class Bird {
  float verticalPosition;

 public:
  Bird(float);

  void draw() const;

  void setVerticalPosition(float);

  std::vector<std::pair<float, float>> getBoundingBox() const;
};

#endif  // FLAPPY_BIRD_COMPONENTS_BIRD_H
