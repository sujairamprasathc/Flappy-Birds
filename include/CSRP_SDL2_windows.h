/****************************************************
*   CSRP_SDL_windows.h                              *
*                                                   *
*   Written by Sujai Ram Prasath C                  *
*                                                   *
*   My own header for creating SDL2 windows         *
*   Base taken from lazyfoo.org                     *
****************************************************/

#ifndef _CSRP_SDL2_WINDOWS_H_
#define _CSRP_SDL2_WINDOWS_H_	1

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <GL/glu.h>

//Define type of callback functions
enum callback_t {
GRAPHICS_RENDERER=0, EVENT_HANDLER
};

class SDL2Window
{
	public:
		//Intializes internals
		SDL2Window();

		//Creates window
		bool init(std::string, int, int, int, int);

		//Handles window events
		void handleEvent( SDL_Event& e );

		//Focuses on window
		void focus();

		//Registers a callback to call when window needs update
		void registerCallback(void (*callback)(SDL_Renderer *mR), callback_t);

		//Registers a callback to call when window needs update
		void registerCallback(void (*callback)(SDL_Event &e), callback_t);

		//Shows windows contents
		void render();

		//Deallocates internals
		void free();

		//Window dimensions
		int getWidth();
		int getHeight();

		//Window focii
		bool hasMouseFocus();
		bool hasKeyboardFocus();
		bool isMinimized();
		bool isShown();

		//Return window pointer
		SDL_Window *returnWindowPointer();

		//Return renderer
		SDL_Renderer* returnRenderer();

	protected:
		//Window data
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
		SDL_GLContext mContext;
		unsigned int windowID;
		std::string windowTitle;

		//Callbacks
		void (*graphicsCallbackFunc)(SDL_Renderer *mR);
		void (*eventCallbackFunc)(SDL_Event &e);

		//Window dimensions
		int windowWidth;
		int windowHeight;

		//Window focus
		bool windowMouseFocus;
		bool windowKeyboardFocus;
		bool windowFullScreen;
		bool windowMinimized;
		bool windowShown;

		//Init OpenGL
		bool initGL();
};

#endif
