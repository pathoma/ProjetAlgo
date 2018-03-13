#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

extern void lire_tableau(char * tableau[], int taille ){
	int i;
for (i=0; i< taille;i++)
	{
		printf("%s|",tableau[i]);  
	}
}