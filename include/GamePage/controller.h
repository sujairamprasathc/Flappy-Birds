#ifndef FLAPPY_BIRD_GAME_PAGE_CONTROLLER_H
#define FLAPPY_BIRD_GAME_PAGE_CONTROLLER_H

#include "decls.h"

#include "../controller.h"

#include "model.h"
#include "view.h"

#include <SDL2/SDL.h>
#include <vector>

class GamePageController : public Controller {
  GamePageView *view;
  GamePageModel *model;

  std::vector<bool> is_Key_Pressed;

  bool keyPressed(unsigned char, int, int);
  bool keyReleased(unsigned char, int, int);

 public:
  GamePageController(GamePageView *, GamePageModel *);

  bool handleEvent(SDL_Event &) override;

  void idleStateHandler();
};

#endif  // FLAPPY_BIRD_GAME_PAGE_CONTROLLER_H
