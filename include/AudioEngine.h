#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include <string>
#include <SDL2/SDL_mixer.h>


extern Mix_Music *gMusic;

//SDL2 Codes
int play_Music(std::string fName);

void stop_Music();

#endif /* AUDIO_ENGINE_H */
