#ifndef FLAPPY_BIRD_OPTIONS_PAGE_VIEW_H
#define FLAPPY_BIRD_OPTIONS_PAGE_VIEW_H

#include <SDL2/SDL.h>

#include "../view.h"
#include "decls.h"

#include "controller.h"
#include "model.h"

class OptionsPageView : public View {
  OptionsPageModel *model;

  SDL_Surface *gOptionsPage;
  SDL_Surface *gScreenSurface;
  SDL_Window *gWindow;

 public:
  OptionsPageView(SDL_Window *, SDL_Surface *, OptionsPageModel *);
  OptionsPageView(const OptionsPageView &) = delete;
  OptionsPageView &operator=(const OptionsPageView &) = delete;
  OptionsPageView(OptionsPageView &&) = default;
  OptionsPageView &operator=(OptionsPageView &&) = default;
  ~OptionsPageView();

  void render() override;
};

#endif  // FLAPPY_BIRD_OPTIONS_PAGE_VIEW_H
