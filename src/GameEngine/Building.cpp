#include "Building.h"
#include <GL/gl.h>

Building::Building(float height, float left, float right) {
  top_left = {left, height};
  bottom_right = {right, -1.0f};
}

void Building::draw() {
  glColor4f(0.289, 0.4882, 0.211, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex3f(top_left.first, top_left.second, -0.7);
  glVertex3f(top_left.first, bottom_right.second, -0.7);
  glVertex3f(bottom_right.first, bottom_right.second, -0.7);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex3f(bottom_right.first, bottom_right.second, -0.7);
  glVertex3f(bottom_right.first, top_left.second, -0.7);
  glVertex3f(top_left.first, top_left.second, -0.7);
  glEnd();
}

void Building::setTopLeft(std::pair<float, float> top_left) {
  this->top_left = top_left;
}

void Building::setBottomRight(std::pair<float, float> bottom_right) {
  this->bottom_right = bottom_right;
}

void Building::moveLeft() {
  this->top_left.first = this->top_left.first - 0.00005;
  this->bottom_right.first = this->bottom_right.first -= 0.00005;

  if (bottom_right.first < -1.0) {
    top_left.first = 1.0;
    bottom_right.first = 1.45;
  }
}
