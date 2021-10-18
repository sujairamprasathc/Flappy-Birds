#include "model.h"

GamePageModel::GamePageModel() {
  this->position_of_bird = 0.0f;
}

void GamePageModel::subscribe(GamePageView *view) {
  this->observerList.push_back(view);
}

void GamePageModel::notify() {
  for (auto &view : this->observerList) {
    view->render();
  }
}

float GamePageModel::getPositionOfBird() {
  return this->position_of_bird;
}

void GamePageModel::setPositionOfBird(float position_of_bird) {
  this->position_of_bird = position_of_bird;
}
