#ifndef GUI_ROOT_VIEW_H
#define GUI_ROOT_VIEW_H 1

#include "StartPage/controller.h"
#include "StartPage/model.h"
#include "StartPage/view.h"

#include "OptionsPage/controller.h"
#include "OptionsPage/model.h"
#include "OptionsPage/view.h"

#include "GamePage/controller.h"
#include "GamePage/model.h"
#include "GamePage/view.h"

#include <pthread.h>

class GuiRoot {
  unsigned viewId;
  bool opt_Page;

  SDL_Window *gWindow;
  SDL_Surface *gScreenSurface;

  StartPageModel *startPageModel;
  StartPageView *startPageView;
  StartPageController *startPageController;

  OptionsPageModel *optionsPageModel;
  OptionsPageView *optionsPageView;
  OptionsPageController *optionsPageController;

  View *view;
  Model *model;
  Controller *controller;

  pthread_t glutMailLoopThread;

  static GuiRoot *instance;

  void initOpenGl();

  GuiRoot();

 public:
  ~GuiRoot();

  static GuiRoot *getInstance();

  void render();
  void handleEvents();

  unsigned getViewId();
  void setViewId(unsigned);
};

#endif  // GUI_ROOT_VIEW_H
