#ifndef GAME_PAGE_CONTROLLER_H
#define GAME_PAGE_CONTROLLER_H 1

#include "decls.h"

#include "../controller.h"

#include "model.h"
#include "view.h"

#include <SDL2/SDL.h>
#include <vector>

class GamePageController {
  GamePageView *view;
  GamePageModel *model;

  std::vector<bool> is_key_pressed;

 public:
  GamePageController(GamePageView *, GamePageModel *);
  bool keyPressed(unsigned char, int, int);
  bool keyReleased(unsigned char, int, int);
};

#endif  // GAME_PAGE_CONTROLLER_H
