#ifndef GAME_END_BOX_H
#define GAME_END_BOX_H

class GameEndBox {
  unsigned score;

  void drawAlertBox() const;

 public:
  GameEndBox(unsigned);

  void draw() const;
};

#endif /* GAME_END_BOX_H */
