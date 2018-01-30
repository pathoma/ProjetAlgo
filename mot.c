#include <stdlib.h>
#include <stdio.h>

int tableauMot[],

void lire_fichier{
	char nomFichier[20];
	FILE * fichier;
	printf("quel est le nom du fichier?");
	scanf("%s",nomFichier);
	fichier=fopen(nomFichier,"r");

int i =0;
char mot[20];
while(!feof(fichier))
	{
		fscanf(fichier,"%s",&mot);
		tableauMot[i]=mot;
		i++;
	}
	fclose(fichier);
}