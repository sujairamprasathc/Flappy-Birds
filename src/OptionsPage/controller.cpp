#include "controller.h"

OptionsPageController::OptionsPageController(OptionsPageView *view,
                                             OptionsPageModel *model) {
  this->view = view;
  this->model = model;
}

bool OptionsPageController::handleEvent(SDL_Event &e) {
  if (e.type == SDL_KEYDOWN) {  // User presses a key
    switch (e.key.keysym.sym) {
      case SDLK_DOWN:
        model->moveCursorDown();
        return true;
      case SDLK_UP:
        model->moveCursorUp();
        return true;
      case SDLK_RETURN:
        switch (model->getCursorPosition()) {
          case 0:
            model->toggleMusic();
            return true;
          case 1:
            model->toggleSound();
            return true;
        }
    }
  }
  return false;
}
