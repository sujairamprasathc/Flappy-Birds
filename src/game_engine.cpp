#include "game_engine.h"

#ifdef _WIN32
#define sleep(int) Sleep(2000)
#endif

// Defnitions to replace ASCII code during keyboard handling
#define ENTER 13
#define ESC 27
#define SPACE 32

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

#define TOP_RIGHT 0

using namespace std;

// Used to control keyboard
bool is_Key_Pressed[256];

// Used to pause the game
bool is_Game_Paused = false;

float obstacle_1_vertex[4][2], obstacle_2_vertex[4][2];

void empty_Function(void) {
  // Might be needed in cases like to pause game
}

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

void pause_Game() {
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

  is_Game_Paused = true;
}

void resume() { is_Game_Paused = false; }

void game_Artist::draw_Building_1() {
  glColor4f(0.289, 0.4882, 0.211, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex3f(vB1[0][0], vB1[0][1], -0.7);
  glVertex3f(vB1[1][0], vB1[1][1], -0.7);
  glVertex3f(vB1[2][0], vB1[2][1], -0.7);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex3f(vB1[2][0], vB1[2][1], -0.7);
  glVertex3f(vB1[3][0], vB1[3][1], -0.7);
  glVertex3f(vB1[0][0], vB1[0][1], -0.7);
  glEnd();

  for (int i = 0; i < 4; i++) vB1[i][0] -= 0.00005;

  if (vB1[3][0] < -1.0) {
    vB1[0][0] = 1.45;
    vB1[1][0] = 1.0;
    vB1[2][0] = 1.0;
    vB1[3][0] = 1.45;
  }
}

void game_Artist::draw_Building_2() {
  glColor4f(0.289, 0.4882, 0.211, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex3f(vB2[0][0], vB2[0][1], -0.7);
  glVertex3f(vB2[1][0], vB2[1][1], -0.7);
  glVertex3f(vB2[2][0], vB2[2][1], -0.7);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex3f(vB2[2][0], vB2[2][1], -0.7);
  glVertex3f(vB2[3][0], vB2[3][1], -0.7);
  glVertex3f(vB2[0][0], vB2[0][1], -0.7);
  glEnd();

  for (int i = 0; i < 4; i++) vB2[i][0] -= 0.00005;

  if (vB2[2][0] < -1.0) {
    vB2[0][0] = 1.0;
    vB2[1][0] = 1.45;
    vB2[2][0] = 1.45;
    vB2[3][0] = 1.0;
  }
}

void game_Artist::draw_Building_3() {
  glColor4f(0.289, 0.4882, 0.211, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex3f(vB3[0][0], vB3[0][1], -0.7);
  glVertex3f(vB3[1][0], vB3[1][1], -0.7);
  glVertex3f(vB3[2][0], vB3[2][1], -0.7);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex3f(vB3[2][0], vB3[2][1], -0.7);
  glVertex3f(vB3[3][0], vB3[3][1], -0.7);
  glVertex3f(vB3[0][0], vB3[0][1], -0.7);
  glEnd();

  for (int i = 0; i < 4; i++) vB3[i][0] -= 0.00005;

  if (vB3[2][0] < -1.0) {
    vB3[0][0] = 1.0;
    vB3[1][0] = 1.45;
    vB3[2][0] = 1.45;
    vB3[3][0] = 1.0;
  }
}

void game_Artist::draw_Building_4() {
  glColor4f(0.289, 0.4882, 0.211, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex3f(vB4[0][0], vB4[0][1], -0.7);
  glVertex3f(vB4[1][0], vB4[1][1], -0.7);
  glVertex3f(vB4[2][0], vB4[2][1], -0.7);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex3f(vB4[2][0], vB4[2][1], -0.7);
  glVertex3f(vB4[3][0], vB3[3][1], -0.7);
  glVertex3f(vB4[0][0], vB4[0][1], -0.7);
  glEnd();

  for (int i = 0; i < 4; i++) vB4[i][0] -= 0.00005;

  if (vB4[2][0] < -1.0) {
    vB4[0][0] = 1.0;
    vB4[1][0] = 1.45;
    vB4[2][0] = 1.45;
    vB4[3][0] = 1.0;
  }
}

void game_Artist::draw_Stars() {
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

void game_Artist::draw_Moon() {
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

game_Artist::game_Artist() {
  vB1[0][0] = -0.4;
  vB1[0][1] = -0.6;
  vB1[1][0] = -0.85;
  vB1[1][1] = -0.6;
  vB1[2][0] = -0.85;
  vB1[2][1] = -1.0;
  vB1[3][0] = -0.4;
  vB1[3][1] = -1.0;
  vB2[0][0] = -0.2;
  vB2[0][1] = -0.3;
  vB2[1][0] = 0.25;
  vB2[1][1] = -0.3;
  vB2[2][0] = 0.25;
  vB2[2][1] = -1.0;
  vB2[3][0] = -0.2;
  vB2[3][1] = -1.0;
  vB3[0][0] = 0.4;
  vB3[0][1] = -0.45;
  vB3[1][0] = 0.85;
  vB3[1][1] = -0.45;
  vB3[2][0] = 0.85;
  vB3[2][1] = -1.0;
  vB3[3][0] = 0.4;
  vB3[3][1] = -1.0;
  vB4[0][0] = 1.05;
  vB4[0][1] = -0.35;
  vB4[1][0] = 1.45;
  vB4[1][1] = -0.35;
  vB4[2][0] = 1.45;
  vB4[2][1] = -1.0;
  vB4[3][0] = 1.05;
  vB4[3][1] = -1.0;
}

void game_Artist::display_Score(int pos, int sco) {
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

  ifstream score_File("../data/scores.data", ios::in);
  score_File >> high_Score;
  score_File.close();

  itoa(high_Score, hScoP, 3);

  glRasterPos2f(-0.95, 0.85);
  glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                   (const unsigned char *)"HIGH SCORE ");
  for (int i = 0; i < 3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hSco[i]);
}

void game_Artist::draw_Bird(float x, float y) {
  float vertex[4][2];

  vertex[0][0] = x + 0.1;
  vertex[0][1] = y + 0.1;
  vertex[1][0] = x - 0.1;
  vertex[1][1] = y + 0.1;
  vertex[2][0] = x - 0.1;
  vertex[2][1] = y - 0.1;
  vertex[3][0] = x + 0.1;
  vertex[3][1] = y - 0.1;

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

void game_Artist::draw_Obstacle(float x[4], float y[4]) {
  glColor4f(0.4, 1.0, 1.0, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex2f(x[0], y[0]);
  glVertex2f(x[1], y[1]);
  glVertex2f(x[2], y[2]);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(x[2], y[2]);
  glVertex2f(x[3], y[3]);
  glVertex2f(x[0], y[0]);
  glEnd();
}

void game_Artist::draw_Backgrounds() {
  draw_Building_1();
  draw_Building_2();
  draw_Building_3();
  draw_Building_4();
  draw_Stars();
  draw_Moon();
}

AI::AI() {
  score = 0;
  velocity = 0.0001;
}

void AI::reset() {
  score = 0;
  velocity = 0.0001;
}

bool AI::check_if_lost(float x, float y) {
  float vertex[4][2];

  vertex[0][0] = x + 0.1;
  vertex[0][1] = y + 0.1;
  vertex[1][0] = x - 0.1;
  vertex[1][1] = y + 0.1;
  vertex[2][0] = x - 0.1;
  vertex[2][1] = y - 0.1;
  vertex[3][0] = x + 0.1;
  vertex[3][1] = y - 0.1;

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 2; j++) {
      if (vertex[i][j] > 1 || vertex[i][j] < -1) return true;
    }

  if (vertex[0][0] > obstacle_1_vertex[2][0] and
      vertex[0][0] < obstacle_1_vertex[3][0] and
      vertex[0][1] > obstacle_1_vertex[2][1])
    return true;
  else if (vertex[1][0] > obstacle_1_vertex[2][0] and
           vertex[1][0] < obstacle_1_vertex[3][0] and
           vertex[1][1] > obstacle_1_vertex[2][1])
    return true;

  if (vertex[0][0] > obstacle_2_vertex[2][0] and
      vertex[0][0] < obstacle_2_vertex[3][0] and
      vertex[2][1] < obstacle_2_vertex[2][1])
    return true;
  else if (vertex[1][0] > obstacle_2_vertex[2][0] and
           vertex[1][0] < obstacle_2_vertex[3][0] and
           vertex[2][1] < obstacle_2_vertex[2][1])
    return true;

  return false;
}

void AI::create_Obstacle(int a) {
  srand(time(NULL));

  switch (a) {
    case 1:
      obstacle_1_vertex[0][0] = 1.2;
      obstacle_1_vertex[0][1] = 1.0;
      obstacle_1_vertex[1][0] = 1.0;
      obstacle_1_vertex[1][1] = 1.0;
      obstacle_1_vertex[2][0] = 1.0;
      obstacle_1_vertex[2][1] = -((rand() % 8) / 10.0) + 0.5;
      obstacle_1_vertex[3][0] = 1.2;
      obstacle_1_vertex[3][1] = obstacle_1_vertex[2][1];
      break;

    case 2:
      obstacle_2_vertex[0][0] = 1.2;
      obstacle_2_vertex[0][1] = -1.0;
      obstacle_2_vertex[1][0] = 1.0;
      obstacle_2_vertex[1][1] = -1.0;
      obstacle_2_vertex[2][0] = 1.0;
      obstacle_2_vertex[2][1] = ((rand() % 8) / 10.0) - 0.5;
      obstacle_2_vertex[3][0] = 1.2;
      obstacle_2_vertex[3][1] = obstacle_2_vertex[2][1];
      break;

    default:
      break;
  }
}

void AI::calc_Score() {
  if ((obstacle_1_vertex[0][0] < 0.0 and
       obstacle_1_vertex[0][0] > -(velocity + 0.00001)) or
      (obstacle_2_vertex[0][0] < 0.0 and
       obstacle_2_vertex[0][0] > -(velocity + 0.00001)))
    score += 1;
}

void AI::calc_Velocity() { velocity = ((double)score / 100000) + 0.0001; }

int AI::get_Score() { return score; }

double AI::get_Velocity() { return velocity; }

void game_End::draw_Alert_Box() {
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

  glutSwapBuffers();
}

void game_End::declare_Over(float score) {
  draw_Alert_Box();
  glColor4f(1.0, 0.4, 0.65, 1.0);
  glRasterPos2f(-0.225, 0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"GAME OVER");
  glColor4f(0.6, 0.1, 0.1, 1.0);
  glRasterPos2f(-0.3, -0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"YOUR SCORE ");
  char sc[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char *scP[10];
  for (int i = 0; i < 10; i++) scP[i] = &sc[i];
  itoa(score, scP, 3);
  for (int i = 0; i < 10; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, sc[i]);
  glutSwapBuffers();
  sleep(2);
}

void game_End::declare_Lost() {
  draw_Alert_Box();
  glColor4f(1.0, 0.4, 0.65, 1.0);
  glRasterPos2f(-0.225, 0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"GAME OVER");
  glColor4f(0.6, 0.1, 0.1, 1.0);
  glRasterPos2f(-0.18, -0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"YOU LOST");
  glutSwapBuffers();
  sleep(2);
}

void game_End::declare_Won() {
  draw_Alert_Box();
  glColor4f(1.0, 0.4, 0.65, 1.0);
  glRasterPos2f(-0.225, 0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"GAME OVER");
  glColor4f(0.6, 0.1, 0.1, 1.0);
  glRasterPos2f(-0.18, -0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"YOU WON");
  glutSwapBuffers();
  sleep(2);
  exit(0);
}

void game_End::declare_Draw() {
  draw_Alert_Box();
  glColor4f(1.0, 0.4, 0.65, 1.0);
  glRasterPos2f(-0.225, 0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"GAME OVER");
  glColor4f(0.6, 0.1, 0.1, 1.0);
  glRasterPos2f(-0.23, -0.05);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,
                   (const unsigned char *)"IT`S A DRAW");
  glutSwapBuffers();
  sleep(2);
  exit(0);
}

enum Colours { BLACK };

Mix_Music *gMusic = NULL;

AI Brain;
game_Artist Artist;

// SDL2 Codes
int play_Music(string fName) {
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) >= 0) {
    gMusic = Mix_LoadMUS(fName.c_str());
    if (gMusic != NULL)
      if (Mix_PlayingMusic() == 0) Mix_PlayMusic(gMusic, -1);
  }

  return 0;
}

void stop_Music() {
  Mix_HaltMusic();
  Mix_FreeMusic(gMusic);
  gMusic = NULL;
  Mix_Quit();
}
