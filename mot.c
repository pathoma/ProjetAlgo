#include <stdlib.h>
#include <stdio.h>

char *tableauMot[50];
int nbmot =0;

void lire_fichier(void){
	/*char nomFichier[15]="list_ani.txt";*/
	char motarecup[20];
	FILE * fichier;

	/*printf("quel est le nom du fichier? : ");
	scanf("%s",nomFichier);*/

	fichier=fopen("list_ani.txt","r");

	
	while(!feof(fichier))
		{
			fscanf(fichier,"%s",motarecup);
			tableauMot[nbmot]=motarecup;
			nbmot++;
		}
		fclose(fichier);
}

