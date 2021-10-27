#include "controller.h"

StartPageController::StartPageController(StartPageView *view,
                                         StartPageModel *model) {
  this->view = view;
  this->model = model;
}

bool StartPageController::handleEvent(SDL_Event &e) {
  if (e.type == SDL_KEYDOWN) {  // User presses a key
    switch (e.key.keysym.sym) {
      case SDLK_DOWN:
        model->moveCursorDown();
        return true;
      case SDLK_UP:
        model->moveCursorUp();
        return true;
    }
  }
  return false;
}
