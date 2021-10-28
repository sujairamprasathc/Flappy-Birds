#ifndef FLAPPY_BIRD_START_PAGE_MODEL_H
#define FLAPPY_BIRD_START_PAGE_MODEL_H

#include "decls.h"

#include "view.h"

#include <vector>

class StartPageModel {
  int cursorPosition;
  std::vector<StartPageView *> observerList;

 public:
  StartPageModel();

  void subscribe(StartPageView *);
  void notify() const;

  int getCursorPosition() const;

  void moveCursorUp();
  void moveCursorDown();
};

#endif  // FLAPPY_BIRD_START_PAGE_MODEL_H
