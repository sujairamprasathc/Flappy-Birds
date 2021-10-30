#include "Scoreboard.h"

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <fstream>

Scoreboard::Scoreboard() { this->score = 0; }

void Scoreboard::draw() const {
  const float red = 1.0;
  const float green = 1.0;
  const float blue = 1.0;
  const float alpha = 1.0;
  glColor4f(red, green, blue, alpha);

  std::string scoreText = std::to_string(this->score);

  glRasterPos2f(0.65, 0.85);  // NOLINT
  glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                   (const unsigned char *)"SCORE ");  // NOLINT
  for (int i = 0; i < scoreText.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);
  }

  unsigned numScores = 0;
  unsigned high_Score = 0;

  std::ifstream score_File("../res/scores.data", std::ios::in);
  score_File >> numScores;
  score_File >> high_Score;
  score_File.close();

  scoreText = std::to_string(high_Score);

  glRasterPos2f(-0.95, 0.85);  // NOLINT
  glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                   (const unsigned char *)"HIGH SCORE ");  // NOLINT
  for (int i = 0; i < scoreText.size(); i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);
  }
}

unsigned Scoreboard::getScore() const { return this->score; }

void Scoreboard::setScore(unsigned score) { this->score = score; }
