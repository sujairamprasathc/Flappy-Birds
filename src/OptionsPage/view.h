#ifndef OPTIONS_PAGE_VIEW_H
#define OPTIONS_PAGE_VIEW_H 1

#include <SDL2/SDL.h>

#include "decls.h"
#include "../view.h"

#include "model.h"
#include "controller.h"

class OptionsPageView : public View {
  OptionsPageModel *model;
  OptionsPageController *controller;

  SDL_Surface *gOptionsPage;
  SDL_Surface *gScreenSurface;
  SDL_Window *gWindow;

 public:
  OptionsPageView(SDL_Window*, SDL_Surface*, SDL_Surface*, OptionsPageModel *model);
  void render();
};

#endif  // OPTIONS_PAGE_VIEW_H
