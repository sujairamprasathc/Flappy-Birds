#ifndef OPTIONS_PAGE_MODEL_H
#define OPTIONS_PAGE_MODEL_H 1

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
  void notify();

  int getCursorPosition();

  void moveCursorUp();
  void moveCursorDown();

  bool isSoundOn();
  bool isMusicOn();

  void toggleSound();
  void toggleMusic();
};

#endif  // OPTIONS_PAGE_MODEL_H
