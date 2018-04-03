 #include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"generateur.h"

int main(){

int nbliste=1;
int niv,X,Y;
	do{
	printf("\nquelle niveau voulez vous pour votre jeu : 1 pour facile 2 pour normal et 3 pour difficile\n");
	scanf("%i", &niv);
	}
	while(niv<0 && niv>3);
	
	switch (niv)
	{
		case 1:
			X=10;
			Y=10;
			break;
		case 2:
			X=15;
			Y=15;
			break;
		case 3:
			X=20;
			Y=20;
		default:
			break;
	}	
	mat_t ma_mat= creer_matrice(X,Y);
	fprintf(stderr,"matrice de %i x %i ", ma_mat.nbc,ma_mat.nbl);
	fprintf(stderr,"la matrice ce creer \n");
	init_matrice(ma_mat);	
	fprintf(stderr,"la matrice s'initialise \n"); 
	
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
	affiche_matrice(ma_mat);
	remplir_final(ma_mat);
	printf("\n");	

	afficher_liste();	
	affiche_matrice(ma_mat);

	while(nbliste>0){
		saisie(ma_mat);
 		nbliste=afficher_liste();
		printf("\n %i \n",nbliste);	
		affiche_matrice(ma_mat);
	}
	
	printf("\n BRAVO VOUS AVEZ FINI LE JEU !!!");
 	
}
