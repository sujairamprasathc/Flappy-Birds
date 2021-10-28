#ifndef GAME_PAGE_MODEL_H
#define GAME_PAGE_MODEL_H 1

#include "decls.h"

#include "view.h"

#include "GameEngine/ComponentFactory.h"

#include <vector>

class GamePageModel {
  std::vector<GamePageView*> observerList;

  float position_of_bird;
  float velocity_of_bird;

  bool _isGamePaused;

  std::vector<Building*> buildings;
  Bird *bird;
  Obstacle *obstacle1, *obstacle2;
  Moon *moon;
  Stars *stars;
  ScoreBoard *scoreBoard;
  PauseElement *pauseElement;

  void onGameOver();

 public:
  GamePageModel(ComponentFactory *);

  void subscribe(GamePageView*);
  void notify() const;

  bool isGamePaused() const;
  void pauseGame();
  void resumeGame();
  void togglePause();

  const Bird& getBird() const;
  const Obstacle& getObstacle1() const;
  const Obstacle& getObstacle2() const;
  const std::vector<Building*>& getBuildings() const;
  const Moon& getMoon() const;
  const Stars& getStars() const;
  const ScoreBoard& getScoreBoard() const;
  const PauseElement& getPauseElement() const;

  float getPositionOfBird() const;
  void setPositionOfBird(float);

  float getVelocityOfBird();
  void setVelocityOfBird(float);

  void createObstacle(int a);
  void reset();
  bool isGameOver() const;
  void calcScore();

  void moveGraphicElementsLeft();
};

#endif  // GAME_PAGE_MODEL_H
