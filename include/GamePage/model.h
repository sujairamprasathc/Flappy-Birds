#ifndef GAME_PAGE_MODEL_H
#define GAME_PAGE_MODEL_H 1

#include "decls.h"

#include "view.h"

#include "../GameEngine/Bird.h"
#include "../GameEngine/Building.h"
#include "../GameEngine/Moon.h"
#include "../GameEngine/Obstacle.h"
#include "../GameEngine/PauseElement.h"
#include "../GameEngine/ScoreBoard.h"
#include "../GameEngine/Stars.h"

#include <vector>

class GamePageModel {
  std::vector<GamePageView*> observerList;

  float position_of_bird;
  float velocity_of_bird;

  bool _isGamePaused;

  std::vector<Building> buildings;
  Bird bird;
  Obstacle obstacle1, obstacle2;
  Moon moon;
  Stars stars;
  ScoreBoard scoreBoard;
  PauseElement pauseElement;

  void onGameOver();

 public:
  GamePageModel();

  void subscribe(GamePageView*);
  void notify();

  bool isGamePaused();
  void pauseGame();
  void resumeGame();
  void togglePause();

  Bird& getBird();
  Obstacle& getObstacle1();
  Obstacle& getObstacle2();
  std::vector<Building>& getBuildings();
  Moon& getMoon();
  Stars& getStars();
  ScoreBoard& getScoreBoard();
  PauseElement& getPauseElement();

  float getPositionOfBird();
  void setPositionOfBird(float);

  float getVelocityOfBird();
  void setVelocityOfBird(float);

  void createObstacle(int a);
  void reset();
  bool isGameOver();
  void calcScore();
};

#endif  // GAME_PAGE_MODEL_H
