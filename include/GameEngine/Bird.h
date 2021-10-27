#ifndef BIRD_H
#define BIRD_H 1

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

#endif  // BIRD_H
