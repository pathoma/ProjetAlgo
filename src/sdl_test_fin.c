/**
* \file sdl_test_fin.c
* \brief .
* \author Renaud 
* \version 2
* \date 04 avril 2018
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include"generateur.h"
#include <ctype.h>
//#include <SDL2/SDL_image.h>



//vrai programme version3

/**
* \fn conv_mat(char c)
* \param caractere present dans la matrice qu'il faut afficher
* \brief fonction qui renvoie la place dans l'alphabet d'un caractere
* \return renvoie un nombre compris entre 0 et 25
*/
int conv_mat(char c){	//	Fonction de conversion d'une matrice de caractere en nb (place alphabet a=0, b=1)
	//int  nbAscii;
	
	//nbAscii=toascii(c);
	return c-'A';		//code ascii de 'a' = 97

}


/**
* \fn clean_up(SDL_Surface *text,TTF_Font* font)
* \param1 recupere un texte de type surface
* ÷param2 recupere une police 
* \brief fonction qui permet de quitter correctement la SDL
*
*/

/*
void clean_up(SDL_Surface *text,TTF_Font* font) { 
	//Free the surfaces 
		//SDL_FreeSurface( background ); 
		SDL_FreeSurface(text); 
	//Close the font that was used 
		TTF_CloseFont(font); 
	//Quit SDL_ttf 
		TTF_Quit(); 
	//Quit SDL 
		SDL_Quit(); 
}
*/


int main(int argc, char ** argv)
{

	char* listeMot[50];
	int nbliste2=0;
	
	int fen = 1;
	SDL_Event event;
	int nbRow=10;
	int nbCol=10;
	int quit = 0;
 	
 	int i,j;
	int nbAscii;
	int cpt=nbRow*nbCol;
	int Wcase = 30;	//30 pixels width
	int Hcase = 30;
	
	int Wcase_mots;	//30 pixels width
	int Hcase_mots;
	
	int dim_menu_h=0;
	int dim_menu_w=0;
	int X=20,Y=20;
	int compteur=0;
	int x1,x2,y1,y2;
	int click=0;
	char* trouver;
		
	
 	int space_bet_w=Wcase+5;	//5px entre chaque case
	int space_bet_h=Hcase+5;
 	int dimWinW=20*space_bet_w+500;
 	int dimWinH=20*space_bet_h+200;
 	
 	
 	
 	char *mat_caractere[40]={
 	"Albatros","Antilope","Buffle","Blaireau","Albatros","Ornithorynque","Antilope","Buffle","Blaireau","Albatros","Antilope","Buffle","Blaireau","Antilope","Buffle","Blaireau","Albatros","Antilope","Buffle","Blaireau","Albatros","Antilope","Buffle","Blaireau","Albatros","Ornithorynque","Antilope","Buffle","Blaireau","Albatros","Antilope","Buffle","Blaireau","Antilope","Zebre","Ornithorynque","Ornithorynque","Ornithorynque","Ornithorynque","Ornithorynque"};
 	
// longueur liste maximum     40 tempo
	int longueur_liste=40;
	char *chaine_menu[11]={"Mots-Melees","START","THEMES","Difficulte","Animaux","Themes2","Theme3","FACILE","NORMAL","DIFFICILE","Lancer la partie"};
	int longueur_chaine=11;
	int difficulte=1,theme=0;
 	

 	char *mat_alphabet[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};// 	/!\ mat_alphabet[0]='A'
	char matrice_cases[10][10]={		//	<--matrice 10x10		temporaire
							{'a','b','c','d','e','f','g','h','i','j'},
							{'a','z','e','r','t','y','u','i','o','p'},
							{'q','s','d','f','g','h','j','k','l','m'},
							{'q','s','d','f','g','h','j','k','l','m'},
							{'q','s','d','f','g','h','j','k','l','m'},
							{'q','s','d','f','g','h','j','k','l','m'},
							{'q','s','d','f','g','h','j','k','l','m'},
							{'q','s','d','f','g','h','j','k','l','m'},
							{'q','s','d','f','g','h','j','k','l','m'},
							{'q','s','d','f','g','h','j','k','l','m'}
						};


 	 /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    } 

	/* Initialisation TTF */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}


	SDL_Window * window = SDL_CreateWindow("SDL_ttf in SDL2",
 	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dimWinW, dimWinH, 0);//		<--dimension fenetre
 	if(window == NULL) {
		fprintf(stderr, "erreur chargement fenetre\n");
		exit(0);
	}
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	if(renderer == NULL) {
		fprintf(stderr, "erreur chargement renderer\n");
		exit(0);
	}
	

	//On initialise la police
	TTF_Font * font = TTF_OpenFont("babybloc.ttf", 25);
	TTF_Font * font2 = TTF_OpenFont("arial.ttf", 50);
	if(font == NULL || font2 == NULL ) {
		fprintf(stderr, "erreur chargement police\n");
		exit(0);
	}	
	//On initialise les couleurs
	SDL_Color blackColor = {0,0,0};
	SDL_Color redColor = {255,0,0};
	SDL_Color backgroundColor = {255,255,100};
	
	//On initialise les surfaces et les textures
	
	SDL_Texture *textures[26];
	
	for(i=0;i<26;i++){
		SDL_Surface * surface = TTF_RenderText_Solid(font,  mat_alphabet[i], blackColor);

		textures[i] = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface( surface);

	}
	
	SDL_Texture *textures_menu[11];

		for(int i=0;i<longueur_chaine;i++){
			SDL_Surface * surface = TTF_RenderText_Blended(font2,  chaine_menu[i], blackColor);

			textures_menu[i] = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_FreeSurface( surface);

		}
	

	 SDL_Texture *textures_mots[39];

		
		
		
	
			

	SDL_SetRenderDrawColor(renderer,255,255,255,0);
	SDL_RenderClear( renderer );

	
	SDL_QueryTexture(textures[0], NULL, NULL, &Wcase, &Hcase);
	SDL_QueryTexture(textures_mots[0], NULL, NULL, &Wcase_mots, &Hcase_mots);

SDL_Rect rect_menu;
			rect_menu.w = 300; 
			rect_menu.h = 100;
			rect_menu.y = 200;
			rect_menu.x = (dimWinW/2)-rect_menu.w/2;

SDL_Rect rect_menu2; 		
			rect_menu2.w = 250; 
			rect_menu2.h = 100;
			rect_menu2.y = 500;
			rect_menu2.x = (dimWinW/2)-rect_menu2.w/2;
			
SDL_Rect rect_menu3;
			rect_menu3.w = 150; 
			rect_menu3.h = 50;
			rect_menu3.y = 220;
			rect_menu3.x = (dimWinW/2)-rect_menu3.w/2;
SDL_Rect rect_menu4; 		
			rect_menu4.w = 200; 
			rect_menu4.h = 50;
			rect_menu4.y = 400;
			rect_menu4.x = (dimWinW/2)-rect_menu3.w/2;
			
SDL_Rect rect_menu5[3];
SDL_Rect rect_menu6[3]; //on a trois niveaux de diff
SDL_Rect rect_menu7;

SDL_Rect rect[400];

SDL_Rect rect_liste;
SDL_Rect rect2[longueur_liste];		
		
				
	if(fen == 1){
 			
 		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);
		SDL_RenderClear(renderer);
		
		
		int dim_menu_h=0;
		int dim_menu_w=0;
		
		SDL_QueryTexture(textures_menu[0], NULL, NULL, &dim_menu_w, &dim_menu_h);


		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);
	
		

		SDL_RenderFillRect(renderer,&rect_menu);
		SDL_RenderCopy(renderer,textures_menu[0],NULL,&rect_menu);
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);
		
		
			
		SDL_RenderFillRect(renderer,&rect_menu2);
		SDL_RenderCopy(renderer,textures_menu[1],NULL,&rect_menu2);
		
		SDL_RenderPresent(renderer);
 		}
	
	
	


	while (quit!=1)
 	{
 	
 	
 		if(fen == 2){
 		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);
		SDL_RenderClear(renderer);
		
		
		SDL_QueryTexture(textures_menu[0], NULL, NULL, &dim_menu_w, &dim_menu_h);


		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);
	
		

		SDL_RenderFillRect(renderer,&rect_menu3);
		SDL_RenderCopy(renderer,textures_menu[2],NULL,&rect_menu3);
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);
		
			
		SDL_RenderFillRect(renderer,&rect_menu4);
		SDL_RenderCopy(renderer,textures_menu[3],NULL,&rect_menu4);
		
		
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);
		 //on a trois themes differents	
			
		
		for(int i=0;i<3;i++){
			rect_menu5[i].w = 150; 
			rect_menu5[i].h = 40;
			rect_menu5[i].y = 300;
			rect_menu5[i].x = (dimWinW/2)-3*rect_menu5[i].w/2+i*170;
			
			SDL_RenderFillRect(renderer,&rect_menu5[i]);
			SDL_RenderCopy(renderer,textures_menu[i+4],NULL,&rect_menu5[i]);
		}
		
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);
				
			
			
		for(int i=0;i<3;i++){
			rect_menu6[i].w = 150; 
			rect_menu6[i].h = 40;
			rect_menu6[i].y = 490;
			rect_menu6[i].x = (dimWinW/2)-3*rect_menu6[i].w/2+i*170;
			
			SDL_RenderFillRect(renderer,&rect_menu6[i]);
			SDL_RenderCopy(renderer,textures_menu[i+7],NULL,&rect_menu6[i]);
		}
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);

			rect_menu7.w = 250; 
			rect_menu7.h = 50;
			rect_menu7.y = 700;
			rect_menu7.x = (dimWinW/2)-rect_menu7.w/2;
			
		SDL_RenderFillRect(renderer,&rect_menu7);
		SDL_RenderCopy(renderer,textures_menu[10],NULL,&rect_menu7);
		
		SDL_RenderPresent(renderer);
		
		
 		}
 		
 		
 		
 	
 		
 		
 		if (fen == 3){
 		
 		
			 	switch (difficulte)
				{
					case 0:
						X=10;
						Y=10;
						break;
					case 1:
						X=15;
						Y=15;
						break;
					case 2:
						X=20;
						Y=20;
					default:
						break;
				}
	
				mat_t ma_mat= creer_matrice(X,Y);
	
				init_matrice(ma_mat);	
				lire_fichier();
				int valeur=alea_mot();
				mot_mat_t monmot=premier_mot(recup_mot(valeur),ma_mat);
				supprime_mot(valeur);
					for(int i = 0; i<ma_mat.nbc*2; i++)
				{
					if(monmot.ligne!=-1)
					{
						monmot=PlacerMot(monmot,ma_mat);
					}
					else
					{
						monmot=Placerlibre(ma_mat);
						
					}
					
				}
				remplir_final(ma_mat);
				fprintf(stderr, "########################\n");
				affiche_matrice(ma_mat);
				afficher_liste();	
 
 				nbliste2=transfert();
				printf("\nnb de mot = %d\n",nbliste2); 
 

 		for(i=0;i<nbliste2;i++){
			SDL_Surface * surface = TTF_RenderText_Blended(font2,  tableauMot[i], blackColor);

			textures_mots[i] = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_FreeSurface( surface);
			//printf("le tableau de mot est %s\n",tableauMot[i]);
		}
		
 
 
 
			
 			
			SDL_RenderClear( renderer );
			SDL_SetRenderDrawColor(renderer, 255, 255, 100, 0);

 	
	 	/*Creation des cases			<-- Changement des parametres	*/
	
		SDL_SetRenderDrawColor(renderer, 230, 130, 60, 0);
	
			SDL_Rect rect_liste;
				rect_liste.x = 20;
				rect_liste.y = 100;
				rect_liste.w = (space_bet_w*X)*0.4;
				rect_liste.h = space_bet_h*Y;
		
		SDL_RenderFillRect(renderer,&rect_liste);

		
		SDL_SetRenderDrawColor(renderer, 230, 130, 60, 0); 
		
		
			
		
		
		for(int i=0;i<nbliste2;i++){
			
				rect2[i].w = 80; 
				rect2[i].h = 20;
				rect2[i].y = 120+i*24;
				rect2[i].x = 40;
				
				SDL_RenderFillRect(renderer,&rect2[i]);
				SDL_RenderCopy(renderer,textures_mots[i],NULL,&rect2[i]);

		}
	
		
		/*
		for(int i=0;i<longueur_liste/2;i++){
			

				rect2.y = 120+i*24;
				rect2.x = 150;
				
				SDL_RenderFillRect(renderer,&rect2);
				SDL_RenderCopy(renderer,textures_mots[i+20],NULL,&rect2);

		}*/
	
	
		SDL_SetRenderDrawColor(renderer, 255,255,200,0);  //		<--couleur case fond
compteur=0;		

		//SDL_Rect rect[X*Y];
		for(int i=0;i<X;i++){
			for(int j=0;j<Y;j++){
				
				//printf("%c",ma_mat.val[j][i]);
				
				nbAscii=conv_mat(ma_mat.val[i][j]);
				//fprintf(stderr, "nbascii[%d][%d]=%d\n", j, i, nbAscii);
				rect[compteur].w = 30; 
				rect[compteur].h = 30;  
				rect[compteur].x = 350+i*35; //Extreme left of the window
				rect[compteur].y = 100+j*35; //Very bottom of the window
				
				SDL_RenderFillRect(renderer,&rect[compteur]);
				SDL_RenderCopy(renderer,textures[nbAscii],NULL,&rect[compteur]);
				
				if(compteur != X*Y-1)compteur++;
			}
		}
		//printf("La lettre pointée est %c\n",ma_mat.val[(event.button.x-350)/34][(event.button.y-100)/34]);
		
		fprintf(stderr, "########################\n"); 
		
	fen=4;
	}


		
		SDL_RenderPresent(renderer);
		
  		SDL_WaitEvent(&event);

  		switch (event.type) {
  			case SDL_QUIT:
   				quit = 1;
   			break;
   			case SDL_MOUSEBUTTONDOWN:
                           
    #if SDL_VERSION_ATLEAST(2,0,2)
                            fprintf(stdout, "\tclics : %d\n",event.button.clicks);
    #endif					
                            fprintf(stdout, "\tposition : %d;%d\n",event.button.x,event.button.y);
                            
                            //if(event.button.x>rect[1].x  &&  event.button.x<rect[1].x+rect[1].w  &&  event.button.y>rect[1].y  &&  event.button.y<rect[1].y+rect[1].h){printf("\n-------------------\n");}
                           
                            if (fen == 1 ){
                            	if(event.button.x > rect_menu2.x  &&  event.button.x < rect_menu2.x + rect_menu2.w  &&  event.button.y > rect_menu2.y  &&  event.button.y < rect_menu2.y + rect_menu2.h){fen = 2;}
                            }
                            /*if((((event.button.x-50)/34))<nbCol  &&  (((event.button.y-50)/34))<nbRow  &&  (((event.button.x-50)/34)+1)>0  &&
                              (((event.button.y-50)/34)+1)>0 )*/
                              //for(i=0;i<longueur_liste/2;i++){
                              	//if(event.button.x > rect2[i].x  &&  event.button.x < rect2[i].x + rect2[i].w  &&  event.button.y > rect2[i].y  &&  event.button.y < rect2[i].y + rect2[i].h){}
                              //}
                           	
                           	if (fen == 2 ){
		                       	for(int i=0;i<3;i++){
		                        	if(event.button.x>rect_menu5[i].x  &&  event.button.x<rect_menu5[i].x+rect_menu5[i].w  &&  event.button.y>rect_menu5[i].y  &&  event.button.y<rect_menu5[i].y+rect_menu5[i].h){theme=i;printf("thème choisi = %i\n",theme);}
		                        }
		                        for(int i=0;i<3;i++){
		                        	if(event.button.x>rect_menu6[i].x  &&  event.button.x<rect_menu6[i].x+rect_menu6[i].w  &&  event.button.y>rect_menu6[i].y  &&  event.button.y<rect_menu6[i].y+rect_menu6[i].h){difficulte=i;printf("difficulté = %i\n",difficulte);}
		                        }
		                        if(event.button.x>rect_menu7.x  &&  event.button.x<rect_menu7.x+rect_menu7.w  &&  event.button.y>rect_menu7.y  &&  event.button.y<rect_menu7.y+rect_menu7.h){fen=3;}
                            }
                            
                            if(fen == 4){
                            	for(i=0;i<X*Y;i++){
                            		switch(click){
                            			case 0:
                            				if(event.button.x>rect[i].x  &&  event.button.x<rect[i].x+rect[i].w  &&  event.button.y>rect[i].y  &&  event.button.y<rect[i].y+rect[i].h){
                            			printf("----E1-----");
                            			 x1 = ((event.button.x-350)/34);y1 = ((event.button.y-100)/34);fprintf(stdout,"La position de x1= %d et y1= %d\n", x1 , y1);click=1;}break;
                            		
                            			case 1:
                            				if(event.button.x>rect[i].x  &&  event.button.x<rect[i].x+rect[i].w  &&  event.button.y>rect[i].y  &&  event.button.y<rect[i].y+rect[i].h){
                            			printf("----E2-----");
                            			 x2 = ((event.button.x-350)/34);y2 = ((event.button.y-100)/34);fprintf(stdout,"La position de x2= %d et y2= %d\n\n\n", x2 , y2);click=0;}break;
                            		}
                            	// ---/!\---Le programme "saisie" oblige à l'utilisateur de rentrer l'id du mot trouver donc non compatible avec la SDL	
                        		}
                            }
                            
                            
  								//fprintf(stdout, "\tposition : %d;%d\n",((event.button.x-350)/34)+1,((event.button.y-100)/34)+1);
  								//printf("La lettre pointée est %c\n",ma_mat.val[(event.button.x-350)/34][(event.button.y-100)/34]);
  								
  							break;
  		}
  							

//	SDL_RenderCopy(renderer, texture, NULL, NULL);
//  SDL_RenderPresent(renderer);
 	}

	//clean_up();

	SDL_DestroyTexture(*textures);
	SDL_DestroyTexture(*textures_menu);
	SDL_DestroyTexture(*textures_mots);
//SDL_DestroyTexture(texture2);
	//SDL_FreeSurface(surface);
	TTF_CloseFont(font);
	TTF_CloseFont(font2);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

 return 0;
}
