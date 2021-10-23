#include "Moon.h"
#include <GL/gl.h>
#include <cmath>

void Moon::draw() {
  float r1 = 0.1, r2 = 0.25, h = 0.5, k = 0.6, deg_to_rad = 3.14 / 180;

  glColor4f(1.0, 1.0, 1.0, 1.0);

  glBegin(GL_POINTS);

  for (float theta = 260.0; theta < 390; theta += 1)
    glVertex2f(r1 * cos(theta * deg_to_rad) + h,
               r1 * sin(theta * deg_to_rad) + k);

  h = h - 0.2 + 0.045;
  k = k + 0.2 - 0.09;

  for (float theta = 305.0; theta < 345; theta += 1)
    glVertex2f(r2 * cos(theta * deg_to_rad) + h,
               r2 * sin(theta * deg_to_rad) + k);

  glEnd();
}
