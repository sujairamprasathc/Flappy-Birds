#include "Bird.h"
#include <GL/gl.h>

using Vertex = std::pair<float, float>;
using Vertices = std::vector<Vertex>;

Bird::Bird(float verticalPosition) {
  this->verticalPosition = verticalPosition;
}

Vertices Bird::computeVertices() const {
  Vertices vertices(4);

  const float birdRadius = 0.1;

  vertices[0].first = birdRadius;
  vertices[0].second = verticalPosition + birdRadius;
  vertices[1].first = -birdRadius;
  vertices[1].second = verticalPosition + birdRadius;
  vertices[2].first = -birdRadius;
  vertices[2].second = verticalPosition - birdRadius;
  vertices[3].first = birdRadius;
  vertices[3].second = verticalPosition - birdRadius;

  return vertices;
}

void Bird::draw() const {
  auto vertices = computeVertices();

  const float red = 1.0;
  const float green = 0.25;
  const float blue = 0.25;
  const float alpha = 1.0;
  glColor4f(red, green, blue, alpha);

  glBegin(GL_POLYGON);
  for (auto &vertex : vertices) {
    glVertex2f(vertex.first, vertex.second);
  }
  glEnd();
}

float Bird::getVerticalPosition() const { return this->verticalPosition; }

void Bird::setVerticalPosition(float verticalPosition) {
  this->verticalPosition = verticalPosition;
}

Vertices Bird::getBoundingBox() const { return this->computeVertices(); }
