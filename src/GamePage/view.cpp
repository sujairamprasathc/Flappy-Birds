#include "view.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include "Components/GameEndBox.h"

GamePageView::GamePageView(GamePageModel *model) {
  model->subscribe(this);
  this->model = model;
}

void GamePageView::render() {
  /*
  Call those functions that have to draw their
  specifics, based on game states
  */
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  if (this->model->isGameOver()) {
    GameEndBox box(this->model->getScoreBoard().getScore());
    box.draw();
    glutSwapBuffers();
    return;
  }

  for (unsigned i = 0; i < 4; ++i) {
    this->model->getBuildings()[i]->draw();
  }
  this->model->getMoon().draw();
  this->model->getStars().draw();

  this->model->getBird().draw();

  this->model->getObstacle1().draw();
  this->model->getObstacle2().draw();

  this->model->getScoreBoard().draw();

  if (this->model->isGamePaused()) {
    this->model->getPauseElement().draw();
  }

  glutSwapBuffers();
}
