#include "AudioEngine.h"

bool MusicPlayer::play(std::string fName) {
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) >= 0) {
    gMusic = Mix_LoadMUS(fName.c_str());
    if (gMusic != NULL)
      if (Mix_PlayingMusic() == 0) Mix_PlayMusic(gMusic, -1);
  }

  return 0;
}

void MusicPlayer::stop() {
  Mix_HaltMusic();
  Mix_FreeMusic(gMusic);
  gMusic = NULL;
  Mix_Quit();
}
