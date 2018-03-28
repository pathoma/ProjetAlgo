
#include"premier_saisie.h"

#define N 15
#define M 15
char mat[N][M];
char* listeMot[50];
int nbliste;
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

// insertion du mot "mot" à partir de (i1,j1) dans la direction "direction"	


char* mot_trouver(int i1,int j1,int i2,int j2){
	
	int i;
	int taille;
	char * trouver = malloc(20 * sizeof(char));
	

	if(i1==i2&&j1<j2){              	//E
		
		taille=(j2-j1)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat[i1][j1+i];
		}
		
		return trouver;
	}
	
	
	if(i1==i2&&j1>j2){              	//O
		
		taille=(j1-j2)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat[i1][j1-i];
		}
		
		return trouver;
	}
	
	else if(j1==j2&&i1<i2){		//S
		taille=(i2-i1)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat[i1+i][j1];
		}
		
		return trouver;
	}
	
	else if(j1==j2&&i2<i1){		//N
		taille=(i1-i2)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat[i1-i][j1];
		}
		
		return trouver;
	}

	else if(i2>i1&&j2>j1){		//SE
		taille=(i2-i1)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat[i1+i][j1+i];
		}
		
		return trouver;
	}

	else if(i1>i2&&j1>j2){		//NO
		taille=(i1-i2)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat[i1-i][j1-i];
		}
		
		return trouver;
	}
	
	else if(i2>i1&&j1>j2){		//SO
		taille=(i2-i1)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat[i1+i][j1-i];
		}
		
		return trouver;
	}

	else if(i1>i2&&j2>j1){		//NE
		taille=(i1-i2)+1;
		for(i=0;i<taille;i++){
			trouver[i]=mat[i1-i][j1+i];
		}
		
		return trouver;
	}
	
}
int verification(char*mot,char*trouver){

	int taille=strlen(mot);
	int i=0;
	int j=0;
	int condi=0;

	printf("motVerif : %s \n",mot);
	printf("trouver Verif : %s \n",trouver);

	for(i=0;i<taille;i++){
		if(mot[i]!=trouver[i]){
			condi=1;
			i=taille;
		}
		printf("%i %c %c \n",i,mot[i],trouver[i]);
	} 
	
	if(condi==1){
		for(i=taille-1;i>=0;i--){ 
			if(mot[j]!=trouver[i]) return 0;
			printf("verif inverse :%i %c %c \n",i,mot[j],trouver[i]);
			j++;
		}
	} else return 1;
	return 1;
}
	
void remplire_liste(){
	int i;
	for(i=0;i<nbliste;i++){
		listeMot[i]=tableauMot[i];
	}
}

void afficher_liste(){
	int i=0;
	printf("\n");
	printf("\n");
	
	for (i=0; i<nbliste;i++)
	{
		printf("%i : %s |",i,listeMot[i]);  
	}
	printf("\n");
	printf("\n");
}
	
int saisie(){

	int deb1,deb2,fin1,fin2;
	int id;
	char* trouver;

	do{
	printf("Veuillez saisir le mot que vous pensez avoir trouvé (indiquer son numéro visible dans la liste au dessu de la grille : ");
	scanf("%i",&id);
	}while(id<0||id>=nbliste);
	
	
	do{
	printf("veuillez saisir l'adresse du DEBUT en commencent par le numéro de ligne puis le numéro de colonne : ");
	scanf("%i%i",&deb1,&deb2);
	}while(deb1>=N||deb2>=M||deb1<0||deb2<0);

	
	do{
	printf("veuillez saisir l'adresse de FIN en commencent par le numéro de ligne puis le numéro de colonne  : ");
	scanf("%i%i",&fin1,&fin2);
	}while(fin1>=N||fin2>=M||fin1<0||fin2<0);


	trouver=mot_trouver(deb1,deb2,fin1,fin2);

	printf("\n");
	
	printf("%s",trouver);
	printf("\n");
	if(verification(listeMot[id],trouver)==1) {
			printf("bien joué, vous avez trouvé un mot");
			listeMot[id]=listeMot[nbliste-1];
			nbmot=nbliste-1;
	}
	else printf("looser ce n'est pas le bon mot \n");
	
}

