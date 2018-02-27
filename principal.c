#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mot.h"

int main(){
	lire_fichier();
	printf("%i", nbmot);	
	lire_tableau_mots();
	printf(" ecriture d'un mot : %s \n",recup_mot(nbmot-1));
	supprime_mot(20);
	lire_tableau_mots();
	printf(" \n \n \n \n \n \n taille: %i \n \n \n \n",taille_mot(10)); 

}