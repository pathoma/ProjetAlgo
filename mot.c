#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include "mot.h"
#include "outil.h"
#include<time.h>
/**
 * ... Documentation ...
 * \file mot.c
 * \brief mot.c est un programme qui a les différentes fonction liés a la liste de mot de départ
 * \author THOMAS Paul
 * \version 1.0
 * \date 3 avril 2018
*/
 


char *tableauMot[];
int nbmot = 0;

/**
 * \fn void lire_fichier(void)
 * \brief insere dans la liste de mot les mots qui sont dans liste_ani.txt et ajoute le nombre de mot dans nbmot
*/

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


/**
 * \fn void lire_tableau_mots(void)
 * \brief affiche le tableau de mots
*/
extern void lire_tableau_mots(void){
	printf("\n lecture des mots \n");
	lire_tableau(tableauMot,nbmot);
	
}

/**
 * \fn char * recup_mot(int i)
 * \brief recupère le mot en i (donné en paramètre)
 * \param i qui représente, la coordonnée dans le tableau ,du mot
 * \return un char * qui est le mot
*/
extern  char * recup_mot(int i){
	
	return tableauMot[i];
}

/**
 * \fn char * recup_mot(int i)
 * \brief supprime le mot en i (donné en paramètre)
 * \param i qui représente ,la coordonnée dans le tableau ,du mot
*/
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

/**
 * \fn  int taille_mot(int i)
 * \brief return la taille du mot en i (donné en paramètre)
 * \param i qui représente, la coordonnée dans le tableau ,du mot
 * \return un int qui est la taille du mot
*/
extern int taille_mot(int i){
return strlen(tableauMot[i]);

}

/**
 * \fn  int alea_mot(void)
 * \brief return la coordonnée d'un mot aléatoire
 * \return un int qui est la coordonné du mot
*/
extern int alea_mot(void){
	
	srand(time(NULL));
	int i=rand()%nbmot;
	return i;
}
