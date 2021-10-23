#include "view.h"

GamePageView::GamePageView(GamePageModel *model)
    : buildings(4, Building(-0.6, -0.85, -0.4)),
      bird(0.0f),
      scoreBoard(TOP_RIGHT) {
  this->model = model;
  this->model->subscribe(this);

  buildings[1] = Building(-0.3, -0.2, 0.25);
  buildings[2] = Building(-0.45, 0.4, 0.85);
  buildings[3] = Building(-0.35, 1.05, 1.45);
}

void GamePageView::drawObstacle() {
  /*
  Function to draw an obstacle
  */
  if (obstacle_1_vertex[0][0] < -1.0) Brain.create_Obstacle(1);

  if (obstacle_2_vertex[0][0] < -1.0) Brain.create_Obstacle(2);

  obstacle1.setTopLeft(obstacle_1_vertex[0][0], obstacle_1_vertex[0][1]);
  obstacle1.setBottomRight(obstacle_1_vertex[2][0], obstacle_1_vertex[2][1]);
  obstacle1.draw();

  obstacle2.setTopLeft(obstacle_2_vertex[0][0], obstacle_2_vertex[0][1]);
  obstacle2.setBottomRight(obstacle_2_vertex[2][0], obstacle_2_vertex[2][1]);
  obstacle2.draw();
}

void GamePageView::render() {
  /*
  Call those functions that have to draw their
  specifics, based on game states
  */
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  for (unsigned i = 0; i < 4; ++i) {
    buildings[i].draw();
    buildings[i].moveLeft();
  }
  moon.draw();
  stars.draw();

  bird.setVerticalPosition(this->model->getPositionOfBird());
  bird.draw();

  drawObstacle();

  scoreBoard.setScore(Brain.get_Score());
  scoreBoard.draw();

  if (is_Game_Paused) pause_Game();

  glutSwapBuffers();
}
