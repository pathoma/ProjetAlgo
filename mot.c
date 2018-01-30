#include <stdlib.h>
#include <stdio.h>

char tableauMot[40];
int nbmot =0;

void lire_fichier(void){
	char nomFichier[20];
	FILE * fichier;
	printf("quel est le nom du fichier?");
	scanf("%s",nomFichier);
	fichier=fopen(nomFichier,"r");

	char mot[100];
	while(!feof(fichier))
		{
			fscanf(fichier,"%s",&mot);
			tableauMot[nbmot]=mot;
			nbmot++;
		}
		fclose(fichier);
}

int main() {

	lire_fichier();
	for(int i=0; i<=nbmot; i++)
	{
		printf("%s\n",tableauMot[i]);

	}
}