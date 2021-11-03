#ifndef FLAPPY_BIRD_COMPONENTS_BIRD_H
#define FLAPPY_BIRD_COMPONENTS_BIRD_H

#include <utility>
#include <vector>

#include "Drawable.h"

class Bird : public Drawable {
  using Vertex = std::pair<float, float>;
  using Vertices = std::vector<Vertex>;

  float verticalPosition;

 protected:
  virtual Vertices computeVertices() const;

 public:
  Bird();

  void draw() const override;
  virtual Vertices getBoundingBox() const;

  virtual float getVerticalPosition() const;
  virtual void setVerticalPosition(float);
};

#endif  // FLAPPY_BIRD_COMPONENTS_BIRD_H
