#include "GameEndBox.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <string>

GameEndBox::GameEndBox(unsigned score) { this->score = score; }

void GameEndBox::drawAlertBox() {
  glColor4f(1.0, 1.0, 1.0, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex2f(-0.4, -0.4);
  glVertex2f(0.4, -0.4);
  glVertex2f(-0.4, 0.4);
  glEnd();
  glBegin(GL_TRIANGLES);
  glVertex2f(-0.4, 0.4);
  glVertex2f(0.4, -0.4);
  glVertex2f(0.4, 0.4);
  glEnd();

  glColor4f(0.0, 0.0, 0.0, 0.0);

  glBegin(GL_LINE_LOOP);
  glVertex2f(-0.35, -0.35);
  glVertex2f(0.35, -0.35);
  glVertex2f(0.35, 0.35);
  glVertex2f(-0.35, 0.35);
  glEnd();
}

void GameEndBox::draw() {
  drawAlertBox();

  glColor4f(1.0, 0.4, 0.65, 1.0);
  glRasterPos2f(-0.225, 0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"GAME OVER");
  glColor4f(0.6, 0.1, 0.1, 1.0);
  glRasterPos2f(-0.3, -0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"YOUR SCORE ");
  std::string scoreText = std::to_string(score);
  for (int i = 0; i < scoreText.size(); i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreText[i]);
}
