#include "CSRP_SDL2_engine.h"

TTF_Font *gFont = NULL;

namespace CSRP_SDL2
{

bool SDL2_Engine_init()
{
if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )   //Starting initiation
    return false;
if( TTF_Init() != 0 )   //Initialize SDL2_ttf
    return false;
if( Mix_Init( MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MODPLUG | MIX_INIT_MP3 | MIX_INIT_OGG |MIX_INIT_FLUIDSYNTH ) < 6 )    //Initialize all music types
    return false;
if ( IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP ) < 4 )
    return false;

atexit(IMG_Quit);
atexit(Mix_Quit);
atexit(TTF_Quit);
atexit(SDL_Quit);

gFont = TTF_OpenFont( "../res/Font.ttf", 14 );

return true;
}

} // end namespace
