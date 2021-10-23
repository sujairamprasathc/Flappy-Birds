#include "Bird.h"
#include <GL/gl.h>

Bird::Bird(float verticalPosition) {
  this->verticalPosition = verticalPosition;
}

void Bird::draw() {
  float vertex[4][2];

  vertex[0][0] = 0.1;
  vertex[0][1] = verticalPosition + 0.1;
  vertex[1][0] = -0.1;
  vertex[1][1] = verticalPosition + 0.1;
  vertex[2][0] = -0.1;
  vertex[2][1] = verticalPosition - 0.1;
  vertex[3][0] = 0.1;
  vertex[3][1] = verticalPosition - 0.1;

  glColor4f(1.0, 0.25, 0.25, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex2f(vertex[0][0], vertex[0][1]);
  glVertex2f(vertex[1][0], vertex[1][1]);
  glVertex2f(vertex[2][0], vertex[2][1]);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(vertex[2][0], vertex[2][1]);
  glVertex2f(vertex[3][0], vertex[3][1]);
  glVertex2f(vertex[0][0], vertex[0][1]);
  glEnd();
}

void Bird::setVerticalPosition(float verticalPosition) {
  this->verticalPosition = verticalPosition;
}
