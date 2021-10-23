#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#ifdef _WIN32
    #define     sleep(int)           Sleep(2000)
#endif


//Defnitions to replace ASCII code during keyboard handling
#define         ENTER           13
#define         ESC             27
#define         SPACE           32


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


#define TOP_RIGHT 0


using namespace std;


//Used to control keyboard
extern bool is_Key_Pressed[256];


//Used to pause the game
extern bool is_Game_Paused;

extern float obstacle_1_vertex[4][2], obstacle_2_vertex[4][2];

void empty_Function(void);

void itoa(int a, char *b[], int c);

void pause_Game();

void resume();

class AI
{
private:
int score;
double velocity;

public:
AI();

    void reset();

    bool check_if_lost(float x, float y);



    void create_Obstacle(int a);

    void calc_Score();

    void calc_Velocity();

    int get_Score();

    double get_Velocity();

};

extern AI Brain;

class game_End
{
/*
    Class to handle end game resources
*/

private:
void draw_Alert_Box();


public:
void declare_Over(float score);

void declare_Lost();

void declare_Won();

void declare_Draw();
};

extern Mix_Music *gMusic;

//SDL2 Codes
int play_Music(string fName);

void stop_Music();

#endif /* GAME_ENGINE_H */
