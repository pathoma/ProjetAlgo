
SDLDIR=/info/etu/l2info/l2info023/Projet/ProjetAlgo/SDL2-2.0.3/SDL2/lib
SDLINC=/info/etu/l2info/l2info023/Projet/ProjetAlgo/SDL2-2.0.3/SDL2/include

all: test_sdl.c
	gcc test_sdl.c -o test_sdl -L${SDLDIR} -lSDL2 -I${SDLINC}


