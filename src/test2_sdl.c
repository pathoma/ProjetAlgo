/* /info/etu/l2info/l2info023/Projet/ProjetAlgo/SDL2-2.0.3/SDL2/lib  */


#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]){
 SDL_Init(SDL_INIT_VIDEO);
 SDL_Surface *fenetre=NULL;
 fenetre=SDL_SetVideoMode(500,500,32);
 SDL_FreeSurface(fenetre);
 SDL_Quit();
 return 0;
}
