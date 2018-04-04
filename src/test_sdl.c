
/* /info/etu/l2info/l2info023/Projet/ProjetAlgo/SDL2-2.0.3/SDL2/lib  */


#include <SDL2/SDL.h>

#include <stdio.h>

int main(int argc, char** argv)
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  640,
                                                                  480,
                                                                  SDL_WINDOW_SHOWN);

	//SDL_FillRect(pWindow,NULL,SDL_MapRGB(pWindow->format,0,0,255));
	
        if( pWindow )
        {
	    SDL_Event event;
	    SDL_WaitEvent(&event);
	    if(event.type==SDL_QUIT){SDL_DestroyWindow(pWindow);}

            SDL_Delay(5000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
}
