#ifndef FLAPPY_BIRD_AUDIO_ENGINE_H
#define FLAPPY_BIRD_AUDIO_ENGINE_H

#include <SDL2/SDL_mixer.h>
#include <string>

class MusicPlayer {
  Mix_Music *gMusic;

 public:
  bool play(std::string fName);
  void stop();
};

#endif  // FLAPPY_BIRD_AUDIO_ENGINE_H
