#ifndef OPTIONS_PAGE_CONTROLLER_H
#define OPTIONS_PAGE_CONTROLLER_H 1

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
  bool handleEvent(SDL_Event &);
};

#endif  // OPTIONS_PAGE_CONTROLLER_H
