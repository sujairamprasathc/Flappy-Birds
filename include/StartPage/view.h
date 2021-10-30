#ifndef FLAPPY_BIRD_START_PAGE_VIEW_H
#define FLAPPY_BIRD_START_PAGE_VIEW_H

#include <SDL2/SDL.h>

#include "../view.h"
#include "decls.h"

#include "controller.h"
#include "model.h"

class StartPageView : public View {
  StartPageModel *model;

  SDL_Surface *gStartPage;
  SDL_Surface *gScreenSurface;
  SDL_Window *gWindow;

 public:
  StartPageView(SDL_Window *, SDL_Surface *, StartPageModel *);
  StartPageView(const StartPageView &) = delete;
  StartPageView &operator=(const StartPageView &) = delete;
  StartPageView(StartPageView &&) = default;
  StartPageView &operator=(StartPageView &&) = default;
  ~StartPageView();

  void render() override;
};

#endif  // FLAPPY_BIRD_START_PAGE_VIEW_H
