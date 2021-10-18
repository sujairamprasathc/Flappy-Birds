#include "view.h"
#include <string>
#include <iostream>

OptionsPageView::OptionsPageView(SDL_Window *gWindow, SDL_Surface *gScreenSurface,
    SDL_Surface *gOptionsPage, OptionsPageModel *model) {
	this->gWindow = gWindow;
	this->gOptionsPage = gOptionsPage;
	this->gScreenSurface = gScreenSurface;
  this->model = model;

  this->model->subscribe(this);
}

void OptionsPageView::render()
{
  std::string filePath = "../res/Options";
  if (this->model->isMusicOn()) {
	  filePath += "_M1";
  }
  else {
	  filePath += "_M0";
  }
  if (this->model->isSoundOn()) {
	  filePath += "_S1";
  }
  else {
	  filePath += "_S0";
  }
  if (this->model->getCursorPosition() == 0) {
	  filePath += "_MP";
  }
  else {
	  filePath += "_SP";
  }
  filePath += ".bmp";
  gOptionsPage = SDL_LoadBMP(filePath.c_str());
  
  SDL_BlitSurface(gOptionsPage, NULL, gScreenSurface, NULL);  // Apply the image
  SDL_UpdateWindowSurface(gWindow);  // Update the surface
}
