#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H 1

class ScoreBoard {
  unsigned score;
  unsigned position;

 public:
  ScoreBoard(unsigned position);

  void draw();

  void setScore(unsigned);
};

#endif // SCORE_BOARD_H
