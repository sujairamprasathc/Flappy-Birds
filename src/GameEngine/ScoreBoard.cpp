#include "ScoreBoard.h"

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <fstream>

#define TOP_RIGHT 0

void itoa(int a, char *b[], int c) {
  /*
      No returning... Directly modify the array pointed to...
      Eg. of modifications...
          1) 0 - 00000....c times
          2) 5 - 00000....c-1 times...5
          3) 152 - 00000....c-3 times....152
  */
  c--;

  for (int i = c, d = 0; i > 0; i--, d++) {
    int x = (a / (pow(10, i)));
    a = a % (int)pow(10, i);
    *b[d] = x + 48;
  }

  *b[c] = (a % 10) + 48;
}

ScoreBoard::ScoreBoard(unsigned position) { this->position = position; }

void ScoreBoard::draw() {
  int sco = this->score;
  int pos = this->position;

  glColor4f(1.0, 1.0, 1.0, 1.0);

  char sc[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char *scP[10];
  for (int i = 0; i < 10; i++) scP[i] = &sc[i];
  itoa(sco, scP, 3);

  if (pos == TOP_RIGHT) {
    glRasterPos2f(0.65, 0.85);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)"SCORE ");
    for (int i = 0; i < 10; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, sc[i]);
  }

  float high_Score;
  char hSco[3], *hScoP[3];

  for (int i = 0; i < 3; i++) hScoP[i] = &hSco[i];

  std::ifstream score_File("../data/scores.data", std::ios::in);
  score_File >> high_Score;
  score_File.close();

  itoa(high_Score, hScoP, 3);

  glRasterPos2f(-0.95, 0.85);
  glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                   (const unsigned char *)"HIGH SCORE ");
  for (int i = 0; i < 3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hSco[i]);
}

void ScoreBoard::setScore(unsigned score) { this->score = score; }
