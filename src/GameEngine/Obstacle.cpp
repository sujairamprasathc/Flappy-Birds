#include "Obstacle.h"
#include <GL/gl.h>

Obstacle::Obstacle() {
  left_x = 0.0f;
  top_y = 0.0f;
  right_x = 0.0f;
  bottom_y = 0.0f;
}

void Obstacle::setTopLeft(float x, float y) {
  this->left_x = x;
  this->top_y = y;
}

void Obstacle::setBottomRight(float x, float y) {
  this->right_x = x;
  this->bottom_y = y;
}

void Obstacle::draw() {
  glColor4f(0.4, 1.0, 1.0, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex2f(right_x, bottom_y);
  glVertex2f(right_x, top_y);
  glVertex2f(left_x, top_y);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(left_x, top_y);
  glVertex2f(left_x, bottom_y);
  glVertex2f(right_x, bottom_y);
  glEnd();
}
