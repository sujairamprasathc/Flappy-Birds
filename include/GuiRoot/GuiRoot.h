#ifndef FLAPPY_BIRD_GUI_ROOT_VIEW_H
#define FLAPPY_BIRD_GUI_ROOT_VIEW_H

#include "StartPage/controller.h"
#include "StartPage/model.h"
#include "StartPage/view.h"

#include "OptionsPage/controller.h"
#include "OptionsPage/model.h"
#include "OptionsPage/view.h"

#include "GamePage/controller.h"
#include "GamePage/model.h"
#include "GamePage/view.h"

#include "AudioEngine.h"

#include <pthread.h>

class GuiRoot {
  bool opt_Page;

  SDL_Window *gWindow;
  SDL_Surface *gScreenSurface;

  StartPageModel *startPageModel;
  StartPageView *startPageView;
  StartPageController *startPageController;

  OptionsPageModel *optionsPageModel;
  OptionsPageView *optionsPageView;
  OptionsPageController *optionsPageController;

  MusicPlayer musicPlayer;

  View *view;
  Model *model;
  Controller *controller;

  pthread_t glutMailLoopThread{};

  static GuiRoot *instance;  // NOLINT

  void initOpenGl();

  GuiRoot();

  void runGame();
  void render();
  bool handleEvent(SDL_Event &);
  static void onGameOver();

 public:
  ~GuiRoot();
  GuiRoot(const GuiRoot &) = delete;
  GuiRoot &operator=(const GuiRoot &) = delete;
  GuiRoot(GuiRoot &&) = delete;
  GuiRoot &operator=(GuiRoot &&) = delete;

  static GuiRoot *getInstance();

  void run();
};

#endif  // FLAPPY_BIRD_GUI_ROOT_VIEW_H
