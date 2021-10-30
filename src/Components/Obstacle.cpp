#include "Obstacle.h"
#include <GL/gl.h>
#include <cstdlib>

Obstacle::Obstacle(unsigned type) {
  this->type = type;
  this->init();
}

void Obstacle::init() {
  if (type == 1) {
    left_x = 1.0F;                          // NOLINT
    top_y = 0.2F - ((rand() % 8) / 10.0F);  // NOLINT
    right_x = 1.2F;                         // NOLINT
    bottom_y = -1.0F;                       // NOLINT
  } else {
    left_x = 2.1F;                             // NOLINT
    bottom_y = 0.7F - ((rand() % 8) / 10.0F);  // NOLINT
    right_x = 2.3F;                            // NOLINT
    top_y = 1.0F;                              // NOLINT
  }
}

void Obstacle::reset() {
  if (type == 1) {
    left_x = 1.0F;                               // NOLINT
    top_y = 0.2F - ((abs(rand()) % 8) / 10.0F);  // NOLINT
    right_x = 1.2F;                              // NOLINT
    bottom_y = -1.0F;                            // NOLINT
  } else {
    left_x = 1.0F;                                  // NOLINT
    bottom_y = 0.7F - ((abs(rand()) % 8) / 10.0F);  // NOLINT
    right_x = 1.2F;                                 // NOLINT
    top_y = 1.0F;                                   // NOLINT
  }
}

float Obstacle::getHeight() const { return top_y; }

void Obstacle::moveLeftBy(float displacement) {
  if (right_x < -1.0F) {
    this->reset();
  }
  left_x -= displacement;
  right_x -= displacement;
}

void Obstacle::draw() const {
  const float red = 0.4;
  const float green = 1.0;
  const float blue = 1.0;
  const float alpha = 1.0;
  glColor4f(red, green, blue, alpha);

  glBegin(GL_POLYGON);
  glVertex2f(right_x, bottom_y);
  glVertex2f(left_x, bottom_y);
  glVertex2f(left_x, top_y);
  glVertex2f(right_x, top_y);
  glEnd();
}

bool Obstacle::isPointInside(std::pair<float, float> point) const {
  bool boundedByX = false;
  bool boundedByY = false;
  if (point.first < right_x && point.first > left_x) {
    boundedByX = true;
  }
  if (point.second < top_y && point.second > bottom_y) {
    boundedByY = true;
  }
  return boundedByX && boundedByY;
}

std::vector<std::pair<float, float>> Obstacle::getBoundingBox() const {
  std::vector<std::pair<float, float>> points;

  points.push_back(std::make_pair(left_x, top_y));
  points.push_back(std::make_pair(left_x, bottom_y));
  points.push_back(std::make_pair(right_x, bottom_y));
  points.push_back(std::make_pair(right_x, top_y));

  return points;
}
