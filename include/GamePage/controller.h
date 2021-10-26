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

  std::vector<bool> is_Key_Pressed;

 public:
  GamePageController(GamePageView *, GamePageModel *);

  void handleEvent();

  bool keyPressed(unsigned char, int, int);
  bool keyReleased(unsigned char, int, int);

  void idleStateHandler();
};

#endif  // GAME_PAGE_CONTROLLER_H
