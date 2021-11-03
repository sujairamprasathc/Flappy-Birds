#ifndef FLAPPY_BIRD_COMPONENTS_GAME_END_BOX_H
#define FLAPPY_BIRD_COMPONENTS_GAME_END_BOX_H

#include "Drawable.h"

class GameEndBox : public Drawable {
  unsigned score;

  static void drawAlertBox();

 public:
  explicit GameEndBox(unsigned);

  void draw() const override;
};

#endif  // FLAPPY_BIRD_COMPONENTS_GAME_END_BOX_H
