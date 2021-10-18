#ifndef GAME_PAGE_MODEL_H
#define GAME_PAGE_MODEL_H 1

#include "decls.h"

#include "view.h"

#include <vector>

class GamePageModel {
  float position_of_bird;
  std::vector<GamePageView*> observerList;

 public:
  GamePageModel();

  void subscribe(GamePageView *);
  void notify();

  float getPositionOfBird();
  void setPositionOfBird(float);
};

#endif  // GAME_PAGE_MODEL_H
