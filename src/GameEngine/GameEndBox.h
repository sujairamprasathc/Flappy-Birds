#ifndef GAME_END_BOX_H
#define GAME_END_BOX_H

class GameEndBox
{
  unsigned score;

  void drawAlertBox();

 public:
  GameEndBox(unsigned);
  
  void draw();
};

#endif /* GAME_END_BOX_H */
