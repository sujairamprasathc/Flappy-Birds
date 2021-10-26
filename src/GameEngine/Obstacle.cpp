#include "Obstacle.h"
#include <GL/gl.h>
#include <cstdlib>

Obstacle::Obstacle(unsigned type) {
  this->type = type;
  this->init();
}

void Obstacle::init() {
  if (type == 1) {
    left_x = 1.0f;
    top_y = 0.2f - ((rand() % 8) / 10.0f);
    right_x = 1.2f;
    bottom_y = -1.0f;
  } else {
    left_x = 2.1f;
    bottom_y = 0.7f - ((rand() % 8) / 10.0f);
    right_x = 2.3f;
    top_y = 1.0f;
  }
}

void Obstacle::reset() {
  if (type == 1) {
    left_x = 1.0f;
    top_y = 0.2f - ((abs(rand()) % 8) / 10.0f);
    right_x = 1.2f;
    bottom_y = -1.0f;
  } else {
    left_x = 1.0f;
    bottom_y = 0.7f - ((abs(rand()) % 8) / 10.0f);
    right_x = 1.2f;
    top_y = 1.0f;
  }
}

float Obstacle::getHeight() { return top_y; }

void Obstacle::moveLeftBy(float displacement) {
  if (right_x < -1.0f) {
    this->reset();
  }
  left_x -= displacement;
  right_x -= displacement;
}

void Obstacle::draw() {
  glColor4f(0.4, 1.0, 1.0, 1.0);

  glBegin(GL_POLYGON);
  glVertex2f(right_x, bottom_y);
  glVertex2f(left_x, bottom_y);
  glVertex2f(left_x, top_y);
  glVertex2f(right_x, top_y);
  glEnd();
}

bool Obstacle::isPointInside(std::pair<float, float> point) {
  bool boundedByX, boundedByY;
  if (point.first < right_x && point.first > left_x) {
    boundedByX = true;
  }
  if (point.second < top_y && point.second > bottom_y) {
    boundedByY = true;
  }
  return boundedByX && boundedByY;
}

std::vector<std::pair<float, float>> Obstacle::getBoundingBox() {
  std::vector<std::pair<float, float>> points;

  points.push_back(std::make_pair(left_x, top_y));
  points.push_back(std::make_pair(left_x, bottom_y));
  points.push_back(std::make_pair(right_x, bottom_y));
  points.push_back(std::make_pair(right_x, top_y));

  return points;
}
