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

using namespace std;

// Used to control keyboard
bool is_Key_Pressed[256];

// Used to pause the game
bool is_Game_Paused = false;

float obstacle_1_vertex[4][2], obstacle_2_vertex[4][2];

void empty_Function(void) {
  // Might be needed in cases like to pause game
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
