#include "PauseElement.h"
#include <GL/gl.h>

void PauseElement::draw() const {
  const float red = 1.0;
  const float green = 1.0;
  const float blue = 1.0;
  const float alpha = 1.0;
  glColor4f(red, green, blue, alpha);

  // Bar 1
  glBegin(GL_POLYGON);
  glVertex2f(-0.15, 0.15);   // NOLINT
  glVertex2f(-0.15, -0.15);  // NOLINT
  glVertex2f(-0.05, -0.15);  // NOLINT
  glVertex2f(-0.05, 0.15);   // NOLINT
  glEnd();

  // Bar 2
  glBegin(GL_POLYGON);
  glVertex2f(0.15, 0.15);   // NOLINT
  glVertex2f(0.15, -0.15);  // NOLINT
  glVertex2f(0.05, -0.15);  // NOLINT
  glVertex2f(0.05, 0.15);   // NOLINT
  glEnd();
}
