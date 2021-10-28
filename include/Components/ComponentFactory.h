#ifndef FLAPPY_BIRD_COMPONENTS_COMPONENT_FACTORY_H
#define FLAPPY_BIRD_COMPONENTS_COMPONENT_FACTORY_H

#include "Bird.h"
#include "Building.h"
#include "Moon.h"
#include "Obstacle.h"
#include "PauseElement.h"
#include "Scoreboard.h"
#include "Stars.h"

class ComponentFactory {
 public:
  virtual Bird* createBird() const;
  virtual Building* createBuilding(unsigned) const;
  virtual Moon* createMoon() const;
  virtual Obstacle* createObstacle(unsigned) const;
  virtual PauseElement* createPauseElement() const;
  virtual Scoreboard* createScoreboard() const;
  virtual Stars* createStars() const;
};

#endif  // FLAPPY_BIRD_COMPONENTS_COMPONENT_FACTORY_H
