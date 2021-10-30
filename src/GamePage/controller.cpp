#include "controller.h"
#include <GL/glut.h>

// Defnitions to replace ASCII code during keyboard handling
constexpr unsigned ENTER = 13;
constexpr unsigned ESC = 27;
constexpr unsigned SPACE = 32;

constexpr unsigned totalNumKeyCodes = 256;

GamePageController::GamePageController(GamePageView *view, GamePageModel *model)
    : is_Key_Pressed(totalNumKeyCodes) {
  this->view = view;
  this->model = model;
}

bool GamePageController::keyPressed(unsigned char key, int x, int y) {
  /*
  Nothing much to do, just change states, except for few
  key strokes, which require action
  */
  switch (key) {
    case ESC:
    case SPACE:
      this->model->togglePause();
      break;
    default:
      break;
  }

  for (int i = 0; i < totalNumKeyCodes; i++) {
    if (key == i) {
      is_Key_Pressed[i] = true;
    }
  }

  return true;
}

bool GamePageController::keyReleased(unsigned char key, int x, int y) {
  /*
  Nothing much to do, just change states
  */
  for (int i = 0; i < totalNumKeyCodes; i++) {
    if (key == i) {
      is_Key_Pressed[i] = false;
    }
  }
  return true;
}

void GamePageController::idleStateHandler() {
  /*
  Entire game's AI and graphics is handled here as
  there is very little user interaction compared
  with the rapidness of loops
  */
  if (this->model->isGamePaused()) {
    return;
  }

  if (!this->model->isGameOver()) {
    float velocity = model->getVelocityOfBird();

    if (is_Key_Pressed['w']) {
      model->setPositionOfBird(model->getPositionOfBird() + velocity);
    } else {
      model->setPositionOfBird(model->getPositionOfBird() - velocity);
    }

    this->model->moveGraphicElementsLeft();

    this->model->calcScore();

    glutPostRedisplay();
  }

  if (this->model->isGameOver()) {
    this->model->pauseGame();
    glutHideWindow();
  }
}
