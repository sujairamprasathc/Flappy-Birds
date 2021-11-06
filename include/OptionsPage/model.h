#ifndef FLAPPY_BIRD_OPTIONS_PAGE_MODEL_H
#define FLAPPY_BIRD_OPTIONS_PAGE_MODEL_H

#include "../model.h"
#include "../view.h"

class OptionsPageModel : public Model {
  int cursorPosition;
  bool _isSoundOn;
  bool _isMusicOn;

 public:
  OptionsPageModel();

  int getCursorPosition() const;

  void moveCursorUp();
  void moveCursorDown();

  bool isSoundOn() const;
  bool isMusicOn() const;

  void toggleSound();
  void toggleMusic();
};

#endif  // FLAPPY_BIRD_OPTIONS_PAGE_MODEL_H
