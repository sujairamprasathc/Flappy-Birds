/****************************************************
*   CSRP_SDL_texture.h                              *
*                                                   *
*   Written by Sujai Ram Prasath C                  *
*                                                   *
*   My own header for creating SDL2 windows         *
*   Base taken from lazyfoo.org                     *
****************************************************/

#ifndef	_CSRP_SDL2_TEXTURE_H_
#define	_CSRP_SDL2_TEXTURE_H_	1

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <GL/glu.h>

#include <string>

//Texture wrapper class
class SDL2Texture
{
	public:
		//Initializes variables
		SDL2Texture(SDL_Renderer*, TTF_Font*);

		//Deallocates memory
		~SDL2Texture();

		//Loads image at specified path
		bool loadFromFile( std::string path );
		
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor, int wrapLength );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//Prevent access to default constructer
		SDL2Texture();

		//The actual hardware texture
		SDL_Texture* mTexture;

		//Renderer
		SDL_Renderer *gRenderer;

		//Font to use
		TTF_Font *gFont;

		//Image dimensions
		int mWidth;
		int mHeight;
};

#endif
