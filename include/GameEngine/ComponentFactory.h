#ifndef COMPONENT_FACTORY_H
#define COMPONENT_FACTORY_H 1

#include "Bird.h"
#include "Building.h"
#include "Moon.h"
#include "Obstacle.h"
#include "PauseElement.h"
#include "ScoreBoard.h"
#include "Stars.h"

class ComponentFactory {
 public:
  virtual Bird* createBird() const;
  virtual Building* createBuilding(unsigned) const;
  virtual Moon* createMoon() const;
  virtual Obstacle* createObstacle(unsigned) const;
  virtual PauseElement* createPauseElement() const;
  virtual ScoreBoard* createScoreBoard() const;
  virtual Stars* createStars() const;
};

#endif // COMPONENT_FACTORY_H
