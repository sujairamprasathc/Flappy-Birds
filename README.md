# Flappy-Birds
A minimalistic graphical implementation of the classic game

## Music Courtesy
The Path of the Goblin King Kevin MacLeod (incompetech.com)
Licensed under Creative Commons: By Attribution 3.0 License
http://creativecommons.org/licenses/by/3.0/

## Prerequisites for building

* The project uses SDL2 library for graphics and multimedia in menu and thus requires SDL2 development libraries
* The project uses freeglut for game window, thus requires OpenGL and freeglut development libraries

#### Developer Packages necessary in Debian Buster

```
libsdl2-dev
libsdl2-ttf-dev
libsdl2-image-dev
libsdl2-gfx-dev
freeglut3-dev
```

## Build Instructions

```bash
cd Flappy-Birds
cmake -S ./ -b ./bin
cd bin
make
```

