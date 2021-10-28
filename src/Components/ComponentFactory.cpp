#include "ComponentFactory.h"

Bird* ComponentFactory::createBird() const { return new Bird(0.0f); }

Building* ComponentFactory::createBuilding(unsigned type) const {
  switch (type) {
    case 1:
      return new Building(-0.6, -0.85, -0.4);
    case 2:
      return new Building(-0.3, -0.2, 0.25);
    case 3:
      return new Building(-0.45, 0.4, 0.85);
    case 4:
      return new Building(-0.35, 1.05, 1.45);
    default:
      throw "Wrong building type";
  }
}

Moon* ComponentFactory::createMoon() const { return new Moon(); }

Obstacle* ComponentFactory::createObstacle(unsigned type) const {
  switch (type) {
    case 1:
      return new Obstacle(1);
    case 2:
      return new Obstacle(2);
    default:
      throw "Wrong building type";
  }
}

PauseElement* ComponentFactory::createPauseElement() const {
  return new PauseElement();
}

Scoreboard* ComponentFactory::createScoreboard() const {
  return new Scoreboard();
}

Stars* ComponentFactory::createStars() const { return new Stars(); }
