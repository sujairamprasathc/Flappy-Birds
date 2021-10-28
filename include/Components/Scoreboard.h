#ifndef FLAPPY_BIRD_COMPONENTS_SCOREBOARD_H
#define FLAPPY_BIRD_COMPONENTS_SCOREBOARD_H

class Scoreboard {
  unsigned score;

 public:
  Scoreboard();

  void draw() const;

  unsigned getScore() const;
  void setScore(unsigned);
};

#endif  // FLAPPY_BIRD_COMPONENTS_SCOREBOARD_H
