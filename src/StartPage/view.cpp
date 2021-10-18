#include "view.h"

StartPageView::StartPageView(SDL_Window *gWindow, SDL_Surface *gScreenSurface,
    SDL_Surface *gStartPage, StartPageModel *model) {
	this->gWindow = gWindow;
	this->gStartPage = gStartPage;
	this->gScreenSurface = gScreenSurface;
  this->model = model;

  this->model->subscribe(this);
}

void StartPageView::render()
{
  if (this->model->getCursorPosition() == 1) {
    gStartPage = SDL_LoadBMP("../res/Start_Page_1.bmp");
  } else if (this->model->getCursorPosition() == 2) {
    gStartPage = SDL_LoadBMP("../res/Start_Page_2.bmp");
  } else {
    gStartPage = SDL_LoadBMP("../res/Start_Page_3.bmp");
  }
  SDL_BlitSurface(gStartPage, NULL, gScreenSurface, NULL);  // Apply the image
  SDL_UpdateWindowSurface(gWindow);  // Update the surface
}
