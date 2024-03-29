#include "view.h"

StartPageView::StartPageView(SDL_Window *gWindow, SDL_Surface *gScreenSurface,
                             StartPageModel *model) {
  this->gWindow = gWindow;
  this->gStartPage = nullptr;
  this->gScreenSurface = gScreenSurface;
  this->model = model;

  this->model->subscribe(this);
}

StartPageView::~StartPageView() { SDL_FreeSurface(gStartPage); }

void StartPageView::render() {
  if (gStartPage != nullptr) {
    SDL_FreeSurface(gStartPage);
  }

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
