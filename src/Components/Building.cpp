#include "Building.h"
#include <GL/gl.h>

Building::Building(float height, float left, float right)
    : top_left{left, height}, bottom_right{right, -1.0F} {}

void Building::draw() const {
  const float red = 0.289;
  const float green = 0.4882;
  const float blue = 0.211;
  const float alpha = 1.0;
  glColor4f(red, green, blue, alpha);

  const float depth = -0.7;

  glBegin(GL_POLYGON);
  glVertex3f(top_left.first, top_left.second, depth);
  glVertex3f(top_left.first, bottom_right.second, depth);
  glVertex3f(bottom_right.first, bottom_right.second, depth);
  glVertex3f(bottom_right.first, top_left.second, depth);
  glEnd();
}

void Building::setTopLeft(std::pair<float, float> top_left) {
  this->top_left = top_left;
}

void Building::setBottomRight(std::pair<float, float> bottom_right) {
  this->bottom_right = bottom_right;
}

void Building::moveLeft() {
  const float displacement = 0.00005;
  this->top_left.first = this->top_left.first - displacement;
  this->bottom_right.first = this->bottom_right.first -= displacement;

  if (bottom_right.first < -1.0) {
    top_left.first = 1.0;
    bottom_right.first = 1.45;  // NOLINT
  }
}
