/****************************************************
*   CSRP_SDL_widgets.h                              *
*                                                   *
*   Written by Sujai Ram Prasath C                  *
*                                                   *
*   My own header containing SDL2 widgets def.      *
****************************************************/

#ifndef _CSRP_SDL2_WIDGETS_H_
#define _CSRP_SDL2_WIDGETS_H_	1

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <GL/glu.h>

#include "CSRP_SDL2_windows.h"
#include "CSRP_SDL2_texture.h"

extern TTF_Font *gFont;

class AlertDialog : private SDL2Window
{
	private:
		std::string alertDialog;
		bool quit;

		void render();
		void handleEvent(SDL_Event &e);

	public:
		AlertDialog();

		bool create(std::string);
		void setAlertDialog(std::string);
		void alert();
		void close();
};

class FilePickerDialog : private SDL2Window
{
	private:
		std::string baseDirectory;

	public:
		FilePickerDialog();
		
		void setBaseDirectory();
};

#endif
