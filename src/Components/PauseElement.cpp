#include "PauseElement.h"
#include <GL/gl.h>

void PauseElement::draw() const {
  glColor4f(1.0, 1.0, 1.0, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex2f(-0.15, 0.15);
  glVertex2f(-0.15, -0.15);
  glVertex2f(-0.05, -0.15);
  glEnd();
  glBegin(GL_TRIANGLES);
  glVertex2f(-0.05, -0.15);
  glVertex2f(-0.05, 0.15);
  glVertex2f(-0.15, 0.15);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(0.15, 0.15);
  glVertex2f(0.15, -0.15);
  glVertex2f(0.05, -0.15);
  glEnd();
  glBegin(GL_TRIANGLES);
  glVertex2f(0.05, -0.15);
  glVertex2f(0.05, 0.15);
  glVertex2f(0.15, 0.15);
  glEnd();
}
