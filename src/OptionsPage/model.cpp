#include "model.h"

OptionsPageModel::OptionsPageModel() {
  this->cursorPosition = 1;
  this->_isSoundOn = false;
  this->_isMusicOn = false;
}

int OptionsPageModel::getCursorPosition() const { return this->cursorPosition; }

void OptionsPageModel::moveCursorDown() {
  this->cursorPosition = (this->cursorPosition + 1) % 2;
  notify();
}

void OptionsPageModel::moveCursorUp() {
  if (this->cursorPosition == 0) {
    this->cursorPosition = 1;
  } else {
    this->cursorPosition = (this->cursorPosition - 1) % 2;
  }
  notify();
}

void OptionsPageModel::subscribe(OptionsPageView *view) {
  this->observerList.push_back(view);
}

void OptionsPageModel::notify() const {
  for (auto &view : this->observerList) {
    view->render();
  }
}

void OptionsPageModel::toggleSound() {
  this->_isSoundOn = !(this->_isSoundOn);
  notify();
}

void OptionsPageModel::toggleMusic() {
  this->_isMusicOn = !(this->_isMusicOn);
  notify();
}

bool OptionsPageModel::isSoundOn() const { return this->_isSoundOn; }

bool OptionsPageModel::isMusicOn() const { return this->_isMusicOn; }
