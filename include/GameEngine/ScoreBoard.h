#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H 1

class ScoreBoard {
  unsigned score;

 public:
  ScoreBoard();

  void draw() const;

  unsigned getScore() const;
  void setScore(unsigned);
};

#endif  // SCORE_BOARD_H
