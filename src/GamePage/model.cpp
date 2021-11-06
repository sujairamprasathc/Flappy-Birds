#include "model.h"

#include <algorithm>
#include <fstream>

GamePageModel::GamePageModel(ComponentFactory* factory)
    : buildings(4), _isGamePaused(false) {
  bird = factory->createBird();
  for (unsigned i = 0; i < 4; ++i) {
    buildings[i] = factory->createBuilding(i + 1);
  }
  moon = factory->createMoon();
  obstacle1 = factory->createObstacle(1);
  obstacle2 = factory->createObstacle(2);
  pauseElement = factory->createPauseElement();
  scoreBoard = factory->createScoreboard();
  stars = factory->createStars();
}

float GamePageModel::getPositionOfBird() const {
  return this->bird->getVerticalPosition();
}

float GamePageModel::getVelocityOfBird() {
  this->velocity_of_bird =
      ((double)this->scoreBoard->getScore() / 100000.0) + 0.0001;  // NOLINT
  return this->velocity_of_bird;
}

void GamePageModel::setVelocityOfBird(float velocity_of_bird) {
  this->velocity_of_bird = velocity_of_bird;
}

void GamePageModel::setPositionOfBird(float position_of_bird) {
  this->bird->setVerticalPosition(position_of_bird);
}

bool GamePageModel::isGamePaused() const { return this->_isGamePaused; }

void GamePageModel::togglePause() {
  this->_isGamePaused = !this->_isGamePaused;
}

void GamePageModel::pauseGame() { this->_isGamePaused = true; }

void GamePageModel::resumeGame() { this->_isGamePaused = false; }

const Bird& GamePageModel::getBird() const { return *(this->bird); }

const Obstacle& GamePageModel::getObstacle1() const {
  return *(this->obstacle1);
}

const Obstacle& GamePageModel::getObstacle2() const {
  return *(this->obstacle2);
}

const std::vector<std::unique_ptr<Building>>& GamePageModel::getBuildings()
    const {
  return this->buildings;
}

const Moon& GamePageModel::getMoon() const { return *(this->moon); }

const Stars& GamePageModel::getStars() const { return *(this->stars); }

const Scoreboard& GamePageModel::getScoreBoard() const {
  return *(this->scoreBoard);
}

const PauseElement& GamePageModel::getPauseElement() const {
  return *(this->pauseElement);
}

bool GamePageModel::isGameOver() const {
  auto birdPoints = bird->getBoundingBox();

  if (std::any_of(birdPoints.begin(), birdPoints.end(), [&](auto point) {
        return obstacle1->isPointInside(point);
      })) {
    return true;
  }

  if (std::any_of(birdPoints.begin(), birdPoints.end(), [&](auto point) {
        return obstacle2->isPointInside(point);
      })) {
    return true;
  }

  if (std::any_of(birdPoints.begin(), birdPoints.end(), [&](auto point) {
        return point.second < -1.0F or point.second > 1.0F;
      })) {
    return true;
  }

  return false;
}

void GamePageModel::calcScore() {
  auto points = obstacle1->getBoundingBox();

  if (points[0].first < 0.0F and
      points[0].first > -(velocity_of_bird + 0.00001)) {  // NOLINT
    this->scoreBoard->setScore(this->scoreBoard->getScore() + 1);
  }

  points = obstacle2->getBoundingBox();

  if (points[0].first < 0.0F and
      points[0].first > -(velocity_of_bird + 0.00001)) {  // NOLINT
    this->scoreBoard->setScore(this->scoreBoard->getScore() + 1);
  }
}

void GamePageModel::moveGraphicElementsLeft() {
  this->obstacle1->moveLeftBy(velocity_of_bird);
  this->obstacle2->moveLeftBy(velocity_of_bird);

  for (auto& building : this->buildings) {
    building->moveLeft();
  }
}
