#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
/**
 * ... Documentation ...
 * \file outil.c
 * \brief outil.c est une liste de fonction global (qu'on pourrais utilsier tel quel dans un autre programme
 * \author THOMAS Paul 
 * \version 1.0
 * \date 3 avril 2018
*/

/**
 * \fn   lire_tableau(char * tableau[], int taille )
 * \brief affiche un tableau de mot
 * \param tableau tableau de mot
 * \param taille est la taille du tableau
 * \return un int qui est la taille du mot
*/
extern void lire_tableau(char * tableau[], int taille ){
	int i;
for (i=0; i< taille;i++)
	{
		printf("%s|",tableau[i]);  
	}
}
