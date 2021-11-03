#ifndef FLAPPY_BIRD_COMPONENTS_DRAWABLE_H
#define FLAPPY_BIRD_COMPONENTS_DRAWABLE_H

class Drawable {
 public:
  virtual ~Drawable() = default;

  virtual void draw() const = 0;
};

#endif  // FLAPPY_BIRD_COMPONENTS_DRAWABLE_H
