#ifndef FLAPPY_BIRD_START_PAGE_CONTROLLER_H
#define FLAPPY_BIRD_START_PAGE_CONTROLLER_H

#include "decls.h"

#include "../controller.h"

#include "model.h"
#include "view.h"

#include <SDL2/SDL.h>

class StartPageController : public Controller {
  StartPageView *view;
  StartPageModel *model;

 public:
  StartPageController(StartPageView *, StartPageModel *);
  bool handleEvent(SDL_Event &event) override;
};

#endif  // FLAPPY_BIRD_START_PAGE_CONTROLLER_H
