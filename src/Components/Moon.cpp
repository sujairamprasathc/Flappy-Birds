#include "Moon.h"
#include <GL/gl.h>
#include <cmath>

void Moon::draw() const {
  float h = 0.5F;  // NOLINT
  float k = 0.6F;  // NOLINT
  const float r1 = 0.1;
  const float r2 = 0.25;
  const float deg_to_rad = 3.14 / 180;

  const unsigned arc1StartAngle = 260;
  const unsigned arc1EndAngle = 390;
  const unsigned arc2StartAngle = 305;
  const unsigned arc2EndAngle = 345;

  const float red = 1.0;
  const float green = 1.0;
  const float blue = 1.0;
  const float alpha = 1.0;
  glColor4f(red, green, blue, alpha);

  glBegin(GL_POINTS);

  // Draw an arc
  for (unsigned theta = arc1StartAngle; theta < arc1EndAngle; theta += 1) {
    glVertex2f(r1 * cos(static_cast<float>(theta) * deg_to_rad) + h,
               r1 * sin(static_cast<float>(theta) * deg_to_rad) + k);
  }

  h = h - 0.2F + 0.045F;  // NOLINT
  k = k + 0.2F - 0.09F;   // NOLINT

  // Draw an arc
  for (unsigned theta = arc2StartAngle; theta < arc2EndAngle; theta += 1) {
    glVertex2f(r2 * cos(static_cast<float>(theta) * deg_to_rad) + h,
               r2 * sin(static_cast<float>(theta) * deg_to_rad) + k);
  }

  glEnd();
}
