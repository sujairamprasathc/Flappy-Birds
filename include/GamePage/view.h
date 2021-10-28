#ifndef FLAPPY_BIRD_GAME_PAGE_VIEW_H
#define FLAPPY_BIRD_GAME_PAGE_VIEW_H

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
  void render() override;
};

#endif  // FLAPPY_BIRD_GAME_PAGE_VIEW_H
