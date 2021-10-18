#include "controller.h"
//#include "../GameView/view.h"

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
      case SDLK_RETURN:
        switch (model->getCursorPosition()) {
          case 1:
            // GameView::getInstance()->setView(3);
            break;
          case 2:
            // GameView::getInstance()->setView(2);
            break;
          case 3:
            // goto QUIT;
            break;
        }
    }
  }
  return false;
}
