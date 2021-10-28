#ifndef FLAPPY_BIRD_OPTIONS_PAGE_MODEL_H
#define FLAPPY_BIRD_OPTIONS_PAGE_MODEL_H

#include "decls.h"

#include "view.h"

#include <vector>

class OptionsPageModel {
  int cursorPosition;
  bool _isSoundOn;
  bool _isMusicOn;
  std::vector<OptionsPageView *> observerList;

 public:
  OptionsPageModel();

  void subscribe(OptionsPageView *);
  void notify() const;

  int getCursorPosition() const;

  void moveCursorUp();
  void moveCursorDown();

  bool isSoundOn() const;
  bool isMusicOn() const;

  void toggleSound();
  void toggleMusic();
};

#endif  // FLAPPY_BIRD_OPTIONS_PAGE_MODEL_H
