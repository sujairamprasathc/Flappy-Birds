/****************************************************
*   CSRP_SDL_widgets.h                              *
*                                                   *
*   Written by Sujai Ram Prasath C                  *
*                                                   *
*   My own header containing SDL2 widgets def.      *
****************************************************/

#include "CSRP_SDL2_widgets.h"

AlertDialog::AlertDialog()
{
	alertDialog=" ";
	quit=false;
}

void AlertDialog::render()
{
	SDL_SetRenderDrawColor( mRenderer, 0x00, 0x00, 0x00, 0xFF );
	SDL_RenderClear( mRenderer );

	SDL_SetRenderDrawColor( mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

	SDL_Rect okBackground = { 140, 50, 40, 20 };
	SDL_RenderFillRect( mRenderer, &okBackground );
	
	SDL2Texture text( mRenderer, gFont );
	SDL_Color textColor = { 0x00, 0x00, 0x00, 0xFF };
	text.loadFromRenderedText( "OK", textColor, 10 );
	text.render( ( 320 - text.getWidth() ) / 2, 52 );

	textColor = { 0xFF, 0xFF, 0xFF, 0xFF };
	text.loadFromRenderedText( alertDialog, textColor, 10 );
	text.render( ( 320 - text.getWidth() ) / 2, 10 );

	SDL_RenderPresent( mRenderer );
}

void AlertDialog::handleEvent(SDL_Event &e)
{
	SDL2Window::handleEvent(e);

	if ( e.type == SDL_MOUSEBUTTONDOWN )
	{
		int x,y;

		SDL_GetMouseState( &x, &y );

		if ( x>140 and x<180 and y>50 and y<70 )
			close();
	}
}

bool AlertDialog::create(std::string WINDOW_TITLE)
{
	if ( SDL2Window::init( WINDOW_TITLE, 320, 80, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED ) == true )
	{
		SDL_HideWindow(mWindow);
		SDL_ShowWindow(mWindow);
		SDL_RaiseWindow(mWindow);
		return true;
	}
	else
		return false;
}

void AlertDialog::setAlertDialog(std::string text)
{
	alertDialog=text;
}

void AlertDialog::alert()
{
	quit=false;
	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0 )
		{
			handleEvent(e);
			render();
		}
	}
}

void AlertDialog::close()
{
	free();
	quit=true;
}

FilePickerDialog::FilePickerDialog()
{
	baseDirectory="";
}

void FilePickerDialog::setBaseDirectory()
{
}
