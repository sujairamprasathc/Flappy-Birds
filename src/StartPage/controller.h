#ifndef START_PAGE_CONTROLLER_H
#define START_PAGE_CONTROLLER_H 1

#include "decls.h"

#include "../controller.h"

#include "view.h"
#include "model.h"

#include <SDL2/SDL.h>

class StartPageController : public Controller {
  StartPageView *view;
  StartPageModel *model;

 public:
  StartPageController(StartPageView *, StartPageModel *);
  bool handleEvent(SDL_Event &);
};

#endif  // START_PAGE_CONTROLLER_H
