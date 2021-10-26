#ifndef OPTIONS_PAGE_VIEW_H
#define OPTIONS_PAGE_VIEW_H 1

#include <SDL2/SDL.h>

#include "../view.h"
#include "decls.h"

#include "controller.h"
#include "model.h"

class OptionsPageView : public View {
  OptionsPageModel *model;
  OptionsPageController *controller;

  SDL_Surface *gOptionsPage;
  SDL_Surface *gScreenSurface;
  SDL_Window *gWindow;

 public:
  OptionsPageView(SDL_Window *, SDL_Surface *, OptionsPageModel *);
  void render();
};

#endif  // OPTIONS_PAGE_VIEW_H
