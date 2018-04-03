#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrice.h"

/**
 * ... Documentation ...
 * \file matrice.c
 * \brief matrice.c comporte toute les fonction utiles a la gestion de la matrice
 * \author THOMAS Paul 
 * \version 1.0
 * \date 3 avril 2018
*/

/**
 * \fn mat_t creer_matrice(int ligne,int colonne)
 * \brief fonction qui creer et renvoie une matrice de taille ligne colonne
 * \param ligne est le nombre de ligne que l'on veux dans la matrice
 * \param colonne est le nombre de colonne que l'on veux dans la matrice
 * \return une variable de type mat_t : une matrice
*/
extern mat_t creer_matrice(int ligne,int colonne)
{
	mat_t ma_mat;
	ma_mat.nbl=ligne;
	ma_mat.nbc=colonne;
	ma_mat.val= (char **) malloc(ma_mat.nbl *sizeof(char *));
	for (int i=0; i<ma_mat.nbl;i++)
	{
		ma_mat.val[i]=(char*) malloc(ma_mat.nbc *sizeof(char));
	}

	return ma_mat;
}

/**
 * \fn mat_t affiche_matrice(mat_t ma_mat)
 * \brief fonction qui affihce la matrice
 * \param ma_mat est la matrice que l'on veut afficher
*/
extern void affiche_matrice(mat_t ma_mat)
{
	printf("\n");
	int i;
	int j;
	int numero=-1;
	int numero2=0;
	int condi=1 ;
	int premier=0;

	
	for(i=-1;i<ma_mat.nbc;i++){
		for(j=0;j<ma_mat.nbl+1;j++){
			
			if(condi==0){
				printf("%2i",numero2);
				numero2++;
				condi=2;
			}
			if(condi==1){
				printf("%2i ",numero);
				numero++;

			} else {
				if(premier==1){
					printf(" ");
					premier=2;
				}
				if(j<ma_mat.nbl)printf("%2c ",ma_mat.val[i][j]);

			}
		}
		condi=0;
		premier=1;
		printf("\n");
	}
}

/**
 * \fn void init_matrice(mat_t ma_mat)
 * \brief fonction qui met dans toutes les case de la matrice en parametre '0'
 * \param ma_mat est la matrice que l'on veut initialiser
*/
extern void init_matrice(mat_t ma_mat){
	int i;
	int j;
	fprintf(stderr,"les valeurs sont %i , %i \n", ma_mat.nbc,ma_mat.nbl);
	for(i=0;i<ma_mat.nbc;i++){
		for(j=0;j<ma_mat.nbl;j++){
			fprintf(stderr,"insertion dans %i %i \n", i,j);
		 	ma_mat.val[i][j]='0';

		}
	}
}

/**
 * \fn void supprim_mat(mat_t ma_mat)
 * \brief fonction qui supprime la matrice
 * \param ma_mat est la matrice que l'on veut supprimer
*/
extern void supprim_mat(mat_t ma_mat)
{
	for (int i=0; i<ma_mat.nbl;i++)
	{
		free(ma_mat.val[i]);
	}
	free(ma_mat.val);
}
