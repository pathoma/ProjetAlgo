 #include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrice.h"

int main(){
/*	lire_fichier();
	printf("%i", nbmot);	
	lire_tableau_mots();
	printf(" ecriture d'un mot : %s \n",recup_mot(nbmot-1));
	supprime_mot(20);
	lire_tableau_mots();
	printf(" \n \n \n \n \n \n taille: %i \n \n \n \n",taille_mot(10)); 
*/
mat_t ma_mat=creer_matrice(10,10);
init_matrice(ma_mat);
affiche_matrice(ma_mat);

}
