#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrice.h"

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

extern void affiche_matrice(mat_t ma_mat)
{
	
	for (int i=0; i<ma_mat.nbl;i++)
	{
		for (int j=0; j<ma_mat.nbc;j++)
		{
			printf(" %c |",ma_mat.val[i][j]);
		}

		printf("\n");
	}
}

extern void init_matrice(mat_t ma_mat){
	int i;
	int j;
	for(i=0;i<ma_mat.nbl;i++){
		for(j=0;j<ma_mat.nbc;j++){
			ma_mat.val[i][j]='0';
		}
	}
}

extern void supprim_mat(mat_t ma_mat)
{
	for (int i=0; i<ma_mat.nbl;i++)
	{
		free(ma_mat.val[i]);
	}
	free(ma_mat.val);
}
