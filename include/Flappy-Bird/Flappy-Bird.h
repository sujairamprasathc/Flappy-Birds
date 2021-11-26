#ifndef FLAPPY_BIRD_H
#define FLAPPY_BIRD_H

#include "controller.h"
#include "model.h"
#include "view.h"

#include "AudioEngine.h"

#include <memory>

class FlappyBird {
  unsigned viewId;

  SDL_Window *gWindow{};
  SDL_Surface *gScreenSurface{};

  MusicPlayer musicPlayer;

  Model *model;
  View *view{};
  Controller *controller{};

  static FlappyBird *instance;  // NOLINT

  FlappyBird();

  void render();
  bool handleEvent(const SDL_Event &);
  void onGameOver();
  static bool initOpenGl();
  bool createWindow();
  bool initWindowForOpenGl();
  bool initWindowForSdl();

 public:
  ~FlappyBird();
  FlappyBird(const FlappyBird &) = delete;
  FlappyBird &operator=(const FlappyBird &) = delete;
  FlappyBird(FlappyBird &&) = delete;
  FlappyBird &operator=(FlappyBird &&) = delete;

  static FlappyBird *getInstance();

  void setViewId(unsigned);

  void run();
};

#endif  // FLAPPY_BIRD_H
