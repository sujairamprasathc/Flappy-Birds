#include "model.h"

#include <algorithm>
#include <fstream>

GamePageModel::GamePageModel()
    : buildings(4, Building(-0.6, -0.85, -0.4)),
      bird(0.0f),
      scoreBoard(TOP_RIGHT),
      obstacle1(1),
      obstacle2(2),
      _isGamePaused(false) {
  buildings[1] = Building(-0.3, -0.2, 0.25);
  buildings[2] = Building(-0.45, 0.4, 0.85);
  buildings[3] = Building(-0.35, 1.05, 1.45);
}

void GamePageModel::subscribe(GamePageView* view) {
  this->observerList.push_back(view);
}

void GamePageModel::notify() {
  for (auto& view : this->observerList) {
    view->render();
  }
}

float GamePageModel::getPositionOfBird() { return this->position_of_bird; }

float GamePageModel::getVelocityOfBird() {
  this->velocity_of_bird =
      ((double)this->scoreBoard.getScore() / 100000) + 0.0001;
  return this->velocity_of_bird;
}

void GamePageModel::setVelocityOfBird(float velocity_of_bird) {
  this->velocity_of_bird = velocity_of_bird;
}

void GamePageModel::setPositionOfBird(float position_of_bird) {
  this->position_of_bird = position_of_bird;
}

bool GamePageModel::isGamePaused() { return this->_isGamePaused; }

void GamePageModel::togglePause() {
  this->_isGamePaused = !this->_isGamePaused;
}

void GamePageModel::pauseGame() { this->_isGamePaused = true; }

void GamePageModel::resumeGame() { this->_isGamePaused = false; }

Bird& GamePageModel::getBird() { return this->bird; }

Obstacle& GamePageModel::getObstacle1() { return this->obstacle1; }

Obstacle& GamePageModel::getObstacle2() { return this->obstacle2; }

std::vector<Building>& GamePageModel::getBuildings() { return this->buildings; }

Moon& GamePageModel::getMoon() { return this->moon; }

Stars& GamePageModel::getStars() { return this->stars; }

ScoreBoard& GamePageModel::getScoreBoard() { return this->scoreBoard; }

PauseElement& GamePageModel::getPauseElement() { return this->pauseElement; }

void GamePageModel::createObstacle(int a) {
  srand(time(NULL));

  switch (a) {
    case 1:
      obstacle1 = Obstacle(1);
      break;

    case 2:
      obstacle2 = Obstacle(2);
      break;

    default:
      break;
  }
}

void GamePageModel::reset() {
  this->velocity_of_bird = 0.0f;
  this->scoreBoard.setScore(0);
}

bool GamePageModel::isGameOver() {
  auto birdPoints = bird.getBoundingBox();

  for (auto point : birdPoints) {
    if (obstacle1.isPointInside(point)) {
      onGameOver();
      return true;
    }
  }

  for (auto point : birdPoints) {
    if (obstacle2.isPointInside(point)) {
      onGameOver();
      return true;
    }
  }

  for (auto point : birdPoints) {
    if (point.second < -1.0f or point.second > 1.0f) {
      onGameOver();
      return true;
    }
  }

  return false;
}

void GamePageModel::calcScore() {
  auto points = obstacle1.getBoundingBox();

  if (points[0].first < 0.0f and
      points[0].first > -(velocity_of_bird + 0.00001)) {
    this->scoreBoard.setScore(this->scoreBoard.getScore() + 1);
  }

  points = obstacle2.getBoundingBox();

  if (points[0].first < 0.0f and
      points[0].first > -(velocity_of_bird + 0.00001)) {
    this->scoreBoard.setScore(this->scoreBoard.getScore() + 1);
  }
}

void GamePageModel::onGameOver() {
  std::ifstream score_File("../res/scores.data", std::ios::in);

  unsigned numScores;
  score_File >> numScores;

  std::vector<unsigned> highScores(numScores);
  for (int i = 0; i < numScores; i++) {
    score_File >> highScores[i];
  }

  score_File.close();

  highScores.push_back(this->scoreBoard.getScore());
  std::sort(highScores.begin(), highScores.end(), std::greater<>());
  if (numScores > 10) {
    highScores.pop_back();
  }

  std::ofstream score_File_Out("../res/scores.data", std::ios::out);
  score_File_Out << numScores << std::endl;
  for (int i = 0; i < numScores; i++) {
    score_File_Out << highScores[i] << std::endl;
  }
  score_File.close();
}
