#ifndef START_PAGE_VIEW_H
#define START_PAGE_VIEW_H 1

#include <SDL2/SDL.h>

#include "../view.h"
#include "decls.h"

#include "model.h"
#include "controller.h"

class StartPageView : public View {
  StartPageModel *model;
  StartPageController *controller;

  SDL_Surface *gStartPage;
  SDL_Surface *gScreenSurface;
  SDL_Window *gWindow;

 public:
  StartPageView(SDL_Window*, SDL_Surface*, SDL_Surface*, StartPageModel *model);
  void render();
};

#endif  // START_PAGE_VIEW_H
