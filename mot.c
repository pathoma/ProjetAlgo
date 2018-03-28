#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include "mot.h"
#include "outil.h"
#include<time.h>

char *tableauMot[];
int nbmot = 0;
 
extern void lire_fichier(void){
	/*char nomFichier[15]="list_ani.txt";*/
	char motarecup[20];
	FILE * fichier;

	/*printf("quel est le nom du fichier? : ");
	scanf("%s",nomFichier);*/

	fichier=fopen("list_ani.txt","r");

	
	while(!feof(fichier))
		{
			fscanf(fichier,"%s",motarecup);
			 tableauMot[nbmot] = malloc (strlen (motarecup) + 1);
			strcpy(tableauMot[nbmot],motarecup);
			
			nbmot++;
		}
		fclose(fichier);
		lire_tableau_mots();
	printf("\n");
}

 
extern void lire_tableau_mots(void){
	printf("\n lecture des mots \n");
	lire_tableau(tableauMot,nbmot);
	
}

extern  char * recup_mot(int i){
	
	return tableauMot[i];
}


extern void supprime_mot(int i){
	if (i==nbmot)
	{
		free(tableauMot[i]);
		nbmot--;
	}
	else
	{
		for (int y=i;y<nbmot;y++)
		{
			tableauMot[y]=tableauMot[y+1];
		}
		free(tableauMot[nbmot]);
		nbmot--;
	}
}

extern int taille_mot(int i){
return strlen(tableauMot[i]);

}

extern int alea_mot(void){
	
	srand(time(NULL));
	int i=rand()%nbmot;
	return i;
}
