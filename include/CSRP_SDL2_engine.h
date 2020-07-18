/****************************************************
*   CSRP_SDL_engine.H                               *
*   version 0.1                                     *
*                                                   *
*   Written by Sujai Ram Prasath C                  *
*                                                   *
*   Written to simplify using SDL2                  *
*   This is the master file, including which        *
*   will inlcude all SDL codes I've written.        *
****************************************************/


#ifndef SDL2_ENGINE_H_
#define SDL2_ENGINE_H_    1


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <GL/glu.h>


extern TTF_Font *gFont;


#include "CSRP_SDL2_texture.h"
#include "CSRP_SDL2_windows.h"
#include "CSRP_SDL2_widgets.h"



namespace CSRP_SDL2     //Prevent name conflicts
{

//Initialize SDL2
bool SDL2_Engine_init();

}   //namespace


#endif /*_CSRP_SDL2_ENGINE_H_*/
