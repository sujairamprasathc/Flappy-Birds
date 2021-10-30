#include "AudioEngine.h"

MusicPlayer::MusicPlayer() { gMusic = nullptr; }

MusicPlayer::~MusicPlayer() {
  if (gMusic != nullptr) {
    Mix_FreeMusic(gMusic);
  }
  gMusic = nullptr;
  Mix_Quit();
}

bool MusicPlayer::play(std::string fName) {
  const int output_sampling_frequency = 44100;
  const int output_channel = 2;  // 1 - mono, 2 - stereo
  const int output_chunksize = 2048;
  if (Mix_OpenAudio(output_sampling_frequency, MIX_DEFAULT_FORMAT,
                    output_channel, output_chunksize) >= 0) {
    gMusic = Mix_LoadMUS(fName.c_str());
    if (gMusic != nullptr) {
      if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(gMusic, -1);
      }
    } else {
      return false;
    }
  }

  return true;
}

void MusicPlayer::stop() {
  Mix_HaltMusic();
  if (gMusic != nullptr) {
    Mix_FreeMusic(gMusic);
  }
  gMusic = nullptr;
}
