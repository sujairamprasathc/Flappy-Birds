#include "Stars.h"
#include <GL/gl.h>

void Stars::draw() {
  glColor4f(1.4, 1.8, 1.6, 1.0);

  glBegin(GL_POINTS);
  glVertex3f(-0.9, 0.7, -1.0);
  glVertex3f(-0.7, 0.5, -1.0);
  glVertex3f(-0.5, 0.65, -1.0);
  glVertex3f(-0.3, 0.6, -1.0);
  glVertex3f(-0.1, 0.5, -1.0);
  glVertex3f(0.1, 0.7, -1.0);
  glVertex3f(0.3, 0.6, -1.0);
  glVertex3f(0.5, 0.75, -1.0);
  glVertex3f(0.6, 0.55, -1.0);
  glVertex3f(0.8, 0.8, -1.0);
  glVertex3f(0.85, 0.5, -1.0);
  glVertex3f(0.95, 0.63, -1.0);
  glEnd();
}