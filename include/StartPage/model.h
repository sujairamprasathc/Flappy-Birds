#ifndef FLAPPY_BIRD_START_PAGE_MODEL_H
#define FLAPPY_BIRD_START_PAGE_MODEL_H

#include "../model.h"
#include "../view.h"

class StartPageModel : public Model {
  int cursorPosition;

 public:
  StartPageModel();

  int getCursorPosition() const;

  void moveCursorUp();
  void moveCursorDown();
};

#endif  // FLAPPY_BIRD_START_PAGE_MODEL_H
