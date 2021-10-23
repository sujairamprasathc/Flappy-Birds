#ifndef GAME_PAGE_VIEW_H
#define GAME_PAGE_VIEW_H 1

#include <SDL2/SDL.h>

#include "../view.h"
#include "decls.h"

#include "controller.h"
#include "model.h"

#include "game_engine.h"

#include "../GameEngine/Building.h"
#include "../GameEngine/Bird.h"
#include "../GameEngine/Obstacle.h"
#include "../GameEngine/Moon.h"
#include "../GameEngine/Stars.h"
#include "../GameEngine/ScoreBoard.h"

#include <vector>

class GamePageView : public View {
  GamePageModel *model;
  GamePageController *controller;

  std::vector<Building> buildings;
  Bird bird;
  Obstacle obstacle1, obstacle2;
  Moon moon;
  Stars stars;
  ScoreBoard scoreBoard;

  void drawObstacle();

 public:
  GamePageView(GamePageModel *model);
  void render();
};

#endif  // GAME_PAGE_VIEW_H
