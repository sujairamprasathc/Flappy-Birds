#ifndef OBSTACLE_H
#define OBSTACLE_H 1

class Obstacle {
  float left_x;
  float top_y;
  float right_x;
  float bottom_y;

 public:
  Obstacle();

  void draw();

  void setTopLeft(float, float);
  void setBottomRight(float, float);
};

#endif // OBSTACLE_H
