#include "controller.h"
//#include "../GameView/view.h"

GamePageController::GamePageController(GamePageView *view, GamePageModel *model)
    : is_key_pressed(255) {
  this->view = view;
  this->model = model;
}

bool GamePageController::keyPressed(unsigned char key, int x, int y) {
  /*
  Nothing much to do, just change states, except for few
  key strokes, which require action
  */
  switch (key) {
    case ESC: {
      if (is_Game_Paused)
        resume();
      else
        pause_Game();

      break;
    }
    case SPACE: {
      if (is_Game_Paused)
        resume();
      else
        pause_Game();

      break;
    }
    default:
      break;
  }

  for (int i = 0; i < 256; i++)
    if (key == i) is_Key_Pressed[i] = true;

  return true;
}

bool GamePageController::keyReleased(unsigned char key, int x, int y) {
  /*
  Nothing much to do, just change states
  */
  for (int i = 0; i < 256; i++)
    if (key == i) is_Key_Pressed[i] = false;
  return true;
}
