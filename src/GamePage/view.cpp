#include "view.h"

GamePageView::GamePageView(GamePageModel *model) {
  this->model = model;
  this->model->subscribe(this);
}

void GamePageView::Obstacle() {
  /*
  Function to draw an obstacle
  */
  if (obstacle_1_vertex[0][0] < -1.0) Brain.create_Obstacle(1);

  if (obstacle_2_vertex[0][0] < -1.0) Brain.create_Obstacle(2);

  float x[4], y[4];

  for (int i = 0; i < 4; i++) {
    x[i] = obstacle_1_vertex[i][0];
    y[i] = obstacle_1_vertex[i][1];
  }

  Artist.draw_Obstacle(x, y);

  for (int i = 0; i < 4; i++) {
    x[i] = obstacle_2_vertex[i][0];
    y[i] = obstacle_2_vertex[i][1];
  }

  Artist.draw_Obstacle(x, y);
}

void GamePageView::render() {
  /*
  Call those functions that have to draw their
  specifics, based on game states
  */
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  Artist.draw_Backgrounds();
  Artist.draw_Bird(0, this->model->getPositionOfBird());
  Obstacle();
  Artist.display_Score(TOP_RIGHT, Brain.get_Score());

  if (is_Game_Paused) pause_Game();

  glutSwapBuffers();
}
