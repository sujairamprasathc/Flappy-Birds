#include "model.h"

StartPageModel::StartPageModel() { this->cursorPosition = 1; }

int StartPageModel::getCursorPosition() const { return this->cursorPosition; }

void StartPageModel::moveCursorDown() {
  this->cursorPosition = (this->cursorPosition + 1) % 3;
  notify();
}

void StartPageModel::moveCursorUp() {
  if (this->cursorPosition == 0) {
    this->cursorPosition = 2;
  } else {
    this->cursorPosition = (this->cursorPosition - 1) % 3;
  }
  notify();
}

void StartPageModel::subscribe(StartPageView *view) {
  this->observerList.push_back(view);
}

void StartPageModel::notify() const {
  for (const auto &view : this->observerList) {
    view->render();
  }
}
