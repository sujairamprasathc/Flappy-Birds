#ifndef GAME_PAGE_CONTROLLER_H
#define GAME_PAGE_CONTROLLER_H 1

#include "decls.h"

#include "../controller.h"

#include "view.h"
#include "model.h"

#include <SDL2/SDL.h>

class GamePageController {
  GamePageView *view;
  GamePageModel *model;

 public:
  GamePageController(GamePageView *, GamePageModel *);
  bool handleEvent(unsigned char, int, int);
};

#endif  // GAME_PAGE_CONTROLLER_H
