#ifndef BUILDING_H
#define BUILDING_H 1

#include <utility>

class Building {
  std::pair<float, float> top_left;
  std::pair<float, float> bottom_right;

 public:
  Building(float height, float left, float right);

  void draw();

  void setTopLeft(std::pair<float, float>);
  void setBottomRight(std::pair<float, float>);

  void moveLeft();
};

#endif // BUILDING_H
