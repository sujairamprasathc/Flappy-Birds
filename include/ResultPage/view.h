#ifndef FLAPPY_BIRD_RESULT_PAGE_VIEW_H
#define FLAPPY_BIRD_RESULT_PAGE_VIEW_H

#include "../view.h"

#include "Components/GameEndBox.h"

class ResultPageView : public View {
  GameEndBox box;

 public:
  ResultPageView(unsigned);

  void render();
};

#endif  // FLAPPY_BIRD_RESULT_PAGE_VIEW_H
