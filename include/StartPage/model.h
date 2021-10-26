#ifndef START_PAGE_MODEL_H
#define START_PAGE_MODEL_H 1

#include "decls.h"

#include "view.h"

#include <vector>

class StartPageModel {
  int cursorPosition;
  std::vector<StartPageView *> observerList;

 public:
  StartPageModel();

  void subscribe(StartPageView *);
  void notify();

  int getCursorPosition();

  void moveCursorUp();
  void moveCursorDown();
};

#endif  // START_PAGE_MODEL_H
