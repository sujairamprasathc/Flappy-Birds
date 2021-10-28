#ifndef FLAPPY_BIRD_OPTIONS_PAGE_CONTROLLER_H
#define FLAPPY_BIRD_OPTIONS_PAGE_CONTROLLER_H

#include "decls.h"

#include "../controller.h"

#include "model.h"
#include "view.h"

#include <SDL2/SDL.h>

class OptionsPageController : public Controller {
  OptionsPageView *view;
  OptionsPageModel *model;

 public:
  OptionsPageController(OptionsPageView *, OptionsPageModel *);
  bool handleEvent(SDL_Event &event) override;
};

#endif  // FLAPPY_BIRD_OPTIONS_PAGE_CONTROLLER_H
