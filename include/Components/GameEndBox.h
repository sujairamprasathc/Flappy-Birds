#ifndef FLAPPY_BIRD_COMPONENTS_GAME_END_BOX_H
#define FLAPPY_BIRD_COMPONENTS_GAME_END_BOX_H

class GameEndBox {
  unsigned score;

  void drawAlertBox() const;

 public:
  GameEndBox(unsigned);

  void draw() const;
};

#endif  // FLAPPY_BIRD_COMPONENTS_GAME_END_BOX_H
