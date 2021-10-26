#ifndef BIRD_H
#define BIRD_H 1

#include <utility>
#include <vector>

class Bird {
  float verticalPosition;

 public:
  Bird(float);

  void draw();

  void setVerticalPosition(float);

  std::vector<std::pair<float, float>> getBoundingBox();
};

#endif  // BIRD_H
