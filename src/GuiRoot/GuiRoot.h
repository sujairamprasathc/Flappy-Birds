#ifndef GUI_ROOT_VIEW_H
#define GUI_ROOT_VIEW_H 1

#include "../StartPage/view.h"

#include "StartPage/controller.h"
#include "StartPage/model.h"
#include "StartPage/view.h"

#include "OptionsPage/controller.h"
#include "OptionsPage/model.h"
#include "OptionsPage/view.h"

#include "GamePage/controller.h"
#include "GamePage/model.h"
#include "GamePage/view.h"

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

 public:
  GuiRoot();
  void render();
  void handleEvents();
};

#endif  // GUI_ROOT_VIEW_H
