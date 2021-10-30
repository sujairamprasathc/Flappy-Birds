#include "ComponentFactory.h"

std::unique_ptr<Bird> ComponentFactory::createBird() const {
  return std::unique_ptr<Bird>{new Bird(0.0F)};
}

std::unique_ptr<Building> ComponentFactory::createBuilding(
    unsigned type) const {
  switch (type) {
    case 1:
      return std::unique_ptr<Building>{
          new Building(-0.6, -0.85, -0.4)};  // NOLINT
    case 2:
      return std::unique_ptr<Building>{
          new Building(-0.3, -0.2, 0.25)};  // NOLINT
    case 3:
      return std::unique_ptr<Building>{
          new Building(-0.45, 0.4, 0.85)};  // NOLINT
    case 4:
      return std::unique_ptr<Building>{
          new Building(-0.35, 1.05, 1.45)};  // NOLINT
    default:
      throw "Wrong building type";
  }
}

std::unique_ptr<Moon> ComponentFactory::createMoon() const {
  return std::unique_ptr<Moon>{new Moon()};
}

std::unique_ptr<Obstacle> ComponentFactory::createObstacle(
    unsigned type) const {
  switch (type) {
    case 1:
      return std::unique_ptr<Obstacle>{new Obstacle(1)};
    case 2:
      return std::unique_ptr<Obstacle>{new Obstacle(2)};
    default:
      throw "Wrong building type";
  }
}

std::unique_ptr<PauseElement> ComponentFactory::createPauseElement() const {
  return std::unique_ptr<PauseElement>{new PauseElement()};
}

std::unique_ptr<Scoreboard> ComponentFactory::createScoreboard() const {
  return std::unique_ptr<Scoreboard>{new Scoreboard()};
}

std::unique_ptr<Stars> ComponentFactory::createStars() const {
  return std::unique_ptr<Stars>{new Stars()};
}
