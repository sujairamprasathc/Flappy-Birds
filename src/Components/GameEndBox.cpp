#include "GameEndBox.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <string>

GameEndBox::GameEndBox(unsigned score) { this->score = score; }

void GameEndBox::drawAlertBox() {
  const float red = 0.4;
  const float green = 1.0;
  const float blue = 1.0;
  const float alpha = 1.0;
  glColor4f(red, green, blue, alpha);

  // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  glBegin(GL_POLYGON);
  glVertex2f(-0.4, -0.4);  // NOLINT
  glVertex2f(0.4, -0.4);   // NOLINT
  glVertex2f(0.4, 0.4);    // NOLINT
  glVertex2f(-0.4, 0.4);   // NOLINT
  glEnd();

  glColor4f(0.0, 0.0, 0.0, 0.0);  // NOLINT

  glBegin(GL_LINE_LOOP);
  glVertex2f(-0.35, -0.35);  // NOLINT
  glVertex2f(0.35, -0.35);   // NOLINT
  glVertex2f(0.35, 0.35);    // NOLINT
  glVertex2f(-0.35, 0.35);   // NOLINT
  glEnd();
  // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
}

void GameEndBox::draw() const {
  drawAlertBox();

  glColor4f(1.0, 0.4, 0.65, 1.0);                // NOLINT
  glRasterPos2f(-0.225, 0.05);                   // NOLINT
  const unsigned char gameOver[] = "GAME OVER";  // NOLINT
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   static_cast<const unsigned char *>(gameOver));
  glColor4f(0.6, 0.1, 0.1, 1.0);                   // NOLINT
  glRasterPos2f(-0.3, -0.05);                      // NOLINT
  const unsigned char yourScore[] = "YOUR SCORE";  // NOLINT
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   static_cast<const unsigned char *>(yourScore));
  std::string scoreText = std::to_string(score);
  for (int i = 0; i < scoreText.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreText[i]);
  }
}
