#include"premier_saisie.h"


/**
 * ... Documentation ...
 * \file premier_saisie.c
 * \brief premier_saisie.c comporte toutes les fonctions utiles a la saisie par le joueur
 * \author MATHEY Benjamin 
 * \version 1.0
 * \date 3 avril 2018
*/

char* listeMot[50];
int nbliste=0; 


/**
 * \fn char* inversion(char*mot)
 * \brief fonction qui reçoit un mot, l'inverse et le retourne
 * \return une variable de type chaine de caractère
*/

// Fonction qui prend le mot l'inverse et retourne son inverse
char* inversion(char*mot){
	
	printf("début inversion \n");
	printf("mot : %s \n",mot);
	
	int i,T;
	T=strlen(mot);
	
	char * inverse = malloc(20 * sizeof(char));	// Variable tempo pour stocker l'inverse 

	for(i=0;i<T;i++){
		inverse[i]=mot[T-1-i];	
	}
	inverse[T] = '\0';

	
	printf("inverse : %s \n",inverse);
	printf("mot : %s \n",mot);
	printf("FIN\n");

	return inverse;
}

/**
 * \fn char* mot_trouver(int i1,int j1,int i2,int j2, mat_t mat)
 * \brief fonction qui reçoit une coordonné de début et une de fin d'un mot a lire
 * \param i1 et j1 corresponde respectivement à la ligne puis la colonne du début du mot à lire 
 * \param i2 et j2 corresponde respectivement à la ligne puis la colonne de la fin du mot à lire
 * \return une variable de type chaine de caractère
*/

// insertion du mot "mot" à partir de (i1,j1) dans la direction "direction"	
char* mot_trouver(int i1,int j1,int i2,int j2, mat_t mat){
	
	int i;
	int taille;
	char * trouver = malloc(20 * sizeof(char));
	

	if(i1==i2&&j1<j2){              	//E
		
		taille=(j2-j1)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat.val[i1][j1+i];
		}
		
	}
	
	
	if(i1==i2&&j1>j2){              	//O
		
		taille=(j1-j2)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat.val[i1][j1-i];
		}
		
	}
	
	else if(j1==j2&&i1<i2){		//S
		taille=(i2-i1)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat.val[i1+i][j1];
		}
		
	}
	
	else if(j1==j2&&i2<i1){		//N
		taille=(i1-i2)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat.val[i1-i][j1];
		}
		
	}

	else if(i2>i1&&j2>j1){		//SE
		taille=(i2-i1)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat.val[i1+i][j1+i];
		}
		
	}

	else if(i1>i2&&j1>j2){		//NO
		taille=(i1-i2)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat.val[i1-i][j1-i];
		}
		
	}
	
	else if(i2>i1&&j1>j2){		//SO
		taille=(i2-i1)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat.val[i1+i][j1-i];
		}
		
	}

	else if(i1>i2&&j2>j1){		//NE
		taille=(i1-i2)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat.val[i1-i][j1+i];
		}
		
	}
	return trouver;
	
}

/**
 * \fn int verification(char*mot,char*trouver)
 * \brief fonction qui reçoit deux mots les compares et renvoit vrai(1) si ils sont identiques et faux(0) sinon
 * \param mot correspond au mot de la liste que le joueur pense avoir trouvé
 * \param trouver correspond au mot que le joueur à saisie via les coordonnés
 * \return vrai ou faux (1 ou 0)
*/

int verification(char*mot,char*trouver){

	int taille=strlen(mot);
	int i=0;
	int j=0;
	int condi=0;
	
	
	//printf("motVerif : %s \n",mot);
	//printf("trouver Verif : %s \n",trouver);
	

	for(i=0;i<taille;i++){
		if(mot[i]!=trouver[i]){
			condi=1;
			i=taille;
		}
		//printf("%i %c %c \n",i,mot[i],trouver[i]);
	} 
	
	if(condi==1){
		for(i=taille-1;i>=0;i--){ 
			if(mot[j]!=trouver[i]) return 0;
			//printf("verif inverse :%i %c %c \n",i,mot[j],trouver[i]);
			j++;
		}
	} else return 1;
	return 1;
}
	
/**
 * \fn int afficher_liste()
 * \brief fonction qui affiche la liste de mot qu'il reste à trouvé en renvoyant le nombre le mot restant
 * \return une variable de type entier
*/


int afficher_liste(){
	int i=0;
	printf("\n");
	printf("\n");
	
	for (i=0; i<nbliste;i++)
	{
		printf("%i : %s |",i,listeMot[i]);  
	}
	printf("\n");
	printf("\n");
	return nbliste;
}

/**
 * \fn void saisie(mat_t mat)
 * \brief fonction qui reçoit la matrice et qui va permettre la saisie  de l'utilisateur
*/

void saisie(mat_t mat){

	int deb1,deb2,fin1,fin2;
	int id;
	char* trouver;

	do{
	printf("Veuillez saisir le mot que vous pensez avoir trouvé (indiquez son numéro visible dans la liste au dessus de la grille : ");
	scanf("%i",&id);
	}while(id<0||id>=nbliste);		//le numéro du mot entré par l'utilisateur doit correspondre à un numéro existant.
	
	
	do{
	printf("veuillez saisir l'adresse du DEBUT en commençant par le numéro de ligne puis le numéro de colonne : ");
	scanf("%i%i",&deb1,&deb2);
	}while(deb1>=mat.nbl||deb2>=mat.nbc||deb1<0||deb2<0);  //les coordonnées doivent appartenir aux dimension de la matrices

	
	do{
	printf("veuillez saisir l'adresse de FIN en commençant par le numéro de ligne puis le numéro de colonne  : ");
	scanf("%i%i",&fin1,&fin2);
	}while(fin1>=mat.nbl||fin2>=mat.nbc||fin1<0||fin2<0);	//les coordonnées doivent appartenir aux dimension de la matrices


	trouver=mot_trouver(deb1,deb2,fin1,fin2,mat);		//récupération du mot lu grâce aux coordonnées fourni par l'utilisateur

	printf("\n");
	
	//printf("%s",trouver);
	printf("\n");
	if(verification(listeMot[id],trouver)==1) {		//comparaison et vérification pour savoir si un mot à été trouvé ou non
			printf("bien joué, vous avez trouvé un mot");
			listeMot[id]=listeMot[nbliste-1];	//remplacement du mot trouvé par le dernier mot de la liste
			nbmot=nbliste-1;
			nbliste=nbliste-1;			//réduction de la taille de la liste
	}
	else printf("looser ce n'est pas le bon mot \n");	
}

/**
 * \fn void ajout_mot(char * mot)
 * \brief fonction qui reçoit un mot alloue de la place dans la liste de mot et l'ajoute 
 * \param mot à ajouter
*/

void ajout_mot(char * mot)
{
	listeMot[nbliste] = malloc (strlen (mot) + 1);
	strcpy(listeMot[nbliste],mot);
	nbliste++;
}


/**
 * \fn void remplissage(mat_t mat)
 * \brief fonction qui intervient après la génération aléatoire et va combler tous les endroit où il n'y a pas encore de lettre en prenant en compte la fréquence de ces lettre dans la langue française
 * \param matrice
*/


void remplissage(mat_t mat){
	int i,j;
	int frec;
	int lettre;  
	char alphabet1[] = "EAISNRTOLU";   	 //10 première lettre les plus utilisées
	char alphabet2[] = "DCMPGBVHF";	   	 //tout le reste
	char alphabet3[] = "QYXJKWZ";	   	 //lettre d'une fréquence inférieur à 1%
	srand(time(NULL));
   
	for(i=0;i<mat.nbl;i++){				
	   	for(j=0;j<mat.nbc;j++){
	   	   	if(mat.val[i][j]=='0'){		//si la case n'est pas encore rempli par une lettre
				frec=rand()%3;
				if(frec!=0){
					lettre =rand()% 9;		
					//printf("%i ",lettre);
					mat.val[i][j]= alphabet1[lettre];
				} else {
					frec=rand()%3;
					if(frec!=0){
						lettre =rand()% 8;
						//printf("%i ",lettre);
						mat.val[i][j]= alphabet2[lettre];
					} else {	
						lettre =rand()% 6;
						//printf("%i ",lettre);
						mat.val[i][j]= alphabet3[lettre];
					}
				}		
			}
	   	}
	}
}

/**
 * \fn int transfert()
 * \brief fonction qui ne sert qu'a renvoyer le nombre de mot restant dans la liste
 * \return entier
*/

int transfert(){
	return nbliste;
}

