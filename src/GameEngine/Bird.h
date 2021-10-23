#ifndef BIRD_H
#define BIRD_H 1

class Bird {
  float verticalPosition;

 public:
  Bird(float);

  void draw();

  void setVerticalPosition(float);
};

#endif // BIRD_H
