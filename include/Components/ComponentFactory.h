#ifndef FLAPPY_BIRD_COMPONENTS_COMPONENT_FACTORY_H
#define FLAPPY_BIRD_COMPONENTS_COMPONENT_FACTORY_H

#include "Bird.h"
#include "Building.h"
#include "Moon.h"
#include "Obstacle.h"
#include "PauseElement.h"
#include "Scoreboard.h"
#include "Stars.h"

#include <memory>

class ComponentFactory {
 public:
  virtual std::unique_ptr<Bird> createBird() const;
  virtual std::unique_ptr<Building> createBuilding(unsigned) const;
  virtual std::unique_ptr<Moon> createMoon() const;
  virtual std::unique_ptr<Obstacle> createObstacle(unsigned) const;
  virtual std::unique_ptr<PauseElement> createPauseElement() const;
  virtual std::unique_ptr<Scoreboard> createScoreboard() const;
  virtual std::unique_ptr<Stars> createStars() const;
};

#endif  // FLAPPY_BIRD_COMPONENTS_COMPONENT_FACTORY_H
