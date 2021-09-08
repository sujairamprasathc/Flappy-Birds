CSRP_SDL2_widgets = include/CSRP_SDL2_widgets.h src/CSRP_SDL2_widgets.cpp
CSRP_SDL2_windows = include/CSRP_SDL2_windows.h src/CSRP_SDL2_windows.cpp
CSRP_SDL2_texture = include/CSRP_SDL2_texture.h src/CSRP_SDL2_texture.cpp
CSRP_SDL2_engine  = include/CSRP_SDL2_engine.h src/CSRP_SDL2_engine.cpp
GAME_ENGINE =  include/game_engine.h
source = src/main.cpp bin/CSRP_SDL2_widgets.o bin/CSRP_SDL2_windows.o bin/CSRP_SDL2_texture.o bin/CSRP_SDL2_engine.o

CFLAGS = -Wall -Wextra -I include
LIB = -lGL -lGLU -lglut -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lSDL2_gfx


Flappy-Birds : bin $(source) $(GAME_ENGINE) $(CSRP_SDL2_widgets) $(CSRP_SDL2_windows) copy_res
	g++ -o bin/Flappy-Birds $(CFLAGS) $(LIB) $(source)

copy_res:
	cp -a res/. bin/

bin/CSRP_SDL2_widgets.o : $(CSRP_SDL2_widgets)
	g++ -o bin/CSRP_SDL2_widgets.o -c src/CSRP_SDL2_widgets.cpp $(CFLAGS)

bin/CSRP_SDL2_windows.o : $(CSRP_SDL2_windows)
	g++ -o bin/CSRP_SDL2_windows.o -c src/CSRP_SDL2_windows.cpp $(CFLAGS)

bin/CSRP_SDL2_texture.o : $(CSRP_SDL2_texture)
	g++ -o bin/CSRP_SDL2_texture.o -c src/CSRP_SDL2_texture.cpp $(CFLAGS)

bin/CSRP_SDL2_engine.o : $(CSRP_SDL2_engine)
	g++ -o bin/CSRP_SDL2_engine.o -c src/CSRP_SDL2_engine.cpp $(CFLAGS)

bin :
ifeq ($(wildcard bin),)
		mkdir bin
endif

clean:
	rm -r bin
