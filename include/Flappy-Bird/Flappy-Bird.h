#ifndef FLAPPY_BIRD_H
#define FLAPPY_BIRD_H

#include "StartPage/controller.h"
#include "StartPage/model.h"
#include "StartPage/view.h"

#include "OptionsPage/controller.h"
#include "OptionsPage/model.h"
#include "OptionsPage/view.h"

#include "GamePage/controller.h"
#include "GamePage/model.h"
#include "GamePage/view.h"

#include "ResultPage/view.h"

#include "AudioEngine.h"

#include <pthread.h>

class FlappyBird {
  bool opt_Page;

  SDL_Window *gWindow;
  SDL_Surface *gScreenSurface;

  StartPageModel *startPageModel;
  StartPageView *startPageView;
  StartPageController *startPageController;

  OptionsPageModel *optionsPageModel;
  OptionsPageView *optionsPageView;
  OptionsPageController *optionsPageController;

  ResultPageView *resultPageView;

  MusicPlayer musicPlayer;

  View *view;
  Model *model;
  Controller *controller;

  pthread_t glutMailLoopThread{};

  static FlappyBird *instance;  // NOLINT

  void initOpenGl();

  FlappyBird();

  void runGame();
  void render();
  bool handleEvent(const SDL_Event &);
  static void onGameOver();

 public:
  ~FlappyBird();
  FlappyBird(const FlappyBird &) = delete;
  FlappyBird &operator=(const FlappyBird &) = delete;
  FlappyBird(FlappyBird &&) = delete;
  FlappyBird &operator=(FlappyBird &&) = delete;

  static FlappyBird *getInstance();

  void run();
};

#endif  // FLAPPY_BIRD_H
