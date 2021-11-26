#ifndef FLAPPY_BIRD_AUDIO_ENGINE_H
#define FLAPPY_BIRD_AUDIO_ENGINE_H

#include <SDL2/SDL_mixer.h>
#include <string>

class MusicPlayer {
  Mix_Music* gMusic;

 public:
  MusicPlayer();
  MusicPlayer(const MusicPlayer&) = delete;
  MusicPlayer& operator=(const MusicPlayer&) = delete;
  MusicPlayer(MusicPlayer&&) = delete;
  MusicPlayer& operator=(MusicPlayer&&) = delete;
  ~MusicPlayer();

  bool play(const std::string& fName);
  void stop();
};

#endif  // FLAPPY_BIRD_AUDIO_ENGINE_H
