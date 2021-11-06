#ifndef FLAPPY_BIRD_GAME_PAGE_MODEL_H
#define FLAPPY_BIRD_GAME_PAGE_MODEL_H

#include "../model.h"
#include "../view.h"

#include "Components/ComponentFactory.h"

class GamePageModel : public Model {
  float velocity_of_bird{};

  bool _isGamePaused;

  std::vector<std::unique_ptr<Building>> buildings;
  std::unique_ptr<Bird> bird;
  std::unique_ptr<Obstacle> obstacle1;
  std::unique_ptr<Obstacle> obstacle2;
  std::unique_ptr<Moon> moon;
  std::unique_ptr<Stars> stars;
  std::unique_ptr<Scoreboard> scoreBoard;
  std::unique_ptr<PauseElement> pauseElement;

 public:
  explicit GamePageModel(ComponentFactory*);

  bool isGamePaused() const;
  void pauseGame();
  void resumeGame();
  void togglePause();

  const Bird& getBird() const;
  const Obstacle& getObstacle1() const;
  const Obstacle& getObstacle2() const;
  const std::vector<std::unique_ptr<Building>>& getBuildings() const;
  const Moon& getMoon() const;
  const Stars& getStars() const;
  const Scoreboard& getScoreBoard() const;
  const PauseElement& getPauseElement() const;

  float getPositionOfBird() const;
  void setPositionOfBird(float);

  float getVelocityOfBird();
  void setVelocityOfBird(float);

  bool isGameOver() const;
  void calcScore();

  void moveGraphicElementsLeft();
};

#endif  // FLAPPY_BIRD_GAME_PAGE_MODEL_H
