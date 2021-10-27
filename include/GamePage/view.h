#ifndef GAME_PAGE_VIEW_H
#define GAME_PAGE_VIEW_H 1

#include <SDL2/SDL.h>

#include "../view.h"
#include "decls.h"

#include "controller.h"
#include "model.h"

class GamePageView : public View {
  const GamePageModel *model;

  void drawObstacle();

 public:
  GamePageView(GamePageModel *model);
  void render();
};

#endif  // GAME_PAGE_VIEW_H
