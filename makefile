CC=gcc

SDLDIR=/info/etu/l2info/l2info023/Projet/ProjetAlgo/SDL2-2.0.3/SDL2_unix/lib
SDLINC=/info/etu/l2info/l2info023/Projet/ProjetAlgo/SDL2-2.0.3/SDL2_unix/include
#makefile pour ttf


SDL_DIR=$(HOME)/Projet/ProjetAlgo/SDL2-2.0.3/SDL2_unix
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf 
#-lSDL2_image
INCLUDES=-I${SDLINC_DIR} 

OBJS = sdl_test_fin.c
OBJ_NAME = prog

all: $(OBJS) matrice.o direction.o mot_mat.o outil.o mot.o premier_saisie.o generateur.o
	${CC} $(OBJS) -o $(OBJ_NAME) matrice.o direction.o mot_mat.o outil.o mot.o premier_saisie.o generateur.o -L${SDLDIR} -lSDL2 -I${SDLINC} ${LIBS} ${INCLUDES}

matrice.o:matrice.c
	gcc -c matrice.c
	
direction.o:direction.c
	gcc -c direction.c
	
mot_mat.o:mot_mat.c
	gcc -c mot_mat.c
	
outil.o: outil.c
	gcc -c outil.c
	
mot.o: mot.c
	gcc -c mot.c
	
premier_saisie.o: premier_saisie.c
	gcc -c premier_saisie.c
	
generateur.o: generateur.c
	gcc -c generateur.c
	





clean: 
	rm -f ${PROG}
	rm -f *.o


