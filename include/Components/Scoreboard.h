#ifndef FLAPPY_BIRD_COMPONENTS_SCOREBOARD_H
#define FLAPPY_BIRD_COMPONENTS_SCOREBOARD_H

#include "Drawable.h"

class Scoreboard : public Drawable {
  unsigned score;

 public:
  Scoreboard();

  void draw() const override;

  unsigned getScore() const;
  void setScore(unsigned);
};

#endif  // FLAPPY_BIRD_COMPONENTS_SCOREBOARD_H
