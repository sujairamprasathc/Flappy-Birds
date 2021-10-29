#ifndef FLAPPY_BIRD_COMPONENTS_BIRD_H
#define FLAPPY_BIRD_COMPONENTS_BIRD_H

#include <utility>
#include <vector>

class Bird {
  using Vertex = std::pair<float, float>;
  using Vertices = std::vector<Vertex>;

  float verticalPosition;

 protected:
  virtual Vertices computeVertices() const;

 public:
  Bird(float);

  virtual void draw() const;
  virtual Vertices getBoundingBox() const;

  virtual void setVerticalPosition(float);
};

#endif  // FLAPPY_BIRD_COMPONENTS_BIRD_H
