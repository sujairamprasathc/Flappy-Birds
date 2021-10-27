#ifndef START_PAGE_VIEW_H
#define START_PAGE_VIEW_H 1

#include <SDL2/SDL.h>

#include "../view.h"
#include "decls.h"

#include "controller.h"
#include "model.h"

class StartPageView : public View {
  StartPageModel *model;
  StartPageController *controller;

  SDL_Surface *gStartPage;
  SDL_Surface *gScreenSurface;
  SDL_Window *gWindow;

 public:
  StartPageView(SDL_Window *, SDL_Surface *, StartPageModel *);
  ~StartPageView();

  void render();
};

#endif  // START_PAGE_VIEW_H
