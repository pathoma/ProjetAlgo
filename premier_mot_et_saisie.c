#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define N 15
#define M 15

char mat[N][M];


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


//Fonction initialisant toutes les cases de la matrice avec le caractère '0'
void init_matrice(void){	
	int i;
	int j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			mat[i][j]='0';
		}
	}
/*
	mat[0][0]='A';
	mat[14][14]='X';
	mat[3][5]='C';
	mat[7][3]='V';	
	mat[1][0]='M';
	mat[2][0]='N';
	mat[5][0]='P';
	mat[1][14]='J';
*/
}



//Fonction affichant la matrice avec un repère allant de 0 à N-1 sur le côté gauche et de 0 à M-1 sur le dessus
void afficher_matrice(void){
	int i;
	int j;
	int numero=-1;
	int numero2=0;
	int condi=1 ;
	int premier=0;

	
	for(i=-1;i<N;i++){
		for(j=0;j<M+1;j++){
			
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
				if(j<M)printf("%2c ",mat[i][j]);

			}
		}
		condi=0;
		premier=1;
		printf("\n");
	}
}

// insertion du mot "mot" à partir de (i1,j1) dans la direction "direction"
void insert_premier(const char*mot,int i1,int j1,int direction){
	
	int fin=0;
	int fin2=0;
	int i,j;
	int T=strlen(mot);
	
	printf("début inséré \n");
	printf("direction : %i , i1 = %i , j1 = %i  \n",direction,i1,j1);

	while(fin2!=1){
		
		while(fin!=1){
			
			if(direction==1){
				
				if(i1-T>=0){
					for(i=0;i<T;i++){
						mat[i1-i][j1]=mot[i];
					}
					fin=1;
					fin2=1;
					printf("direction final : %i\n",direction);
				} else fin=1;
			}
			
			if(direction==2){
				if(i1-T>=0 && j1+T<M){
					for(i=0;i<T;i++){
						mat[i1-i][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
					printf("direction final : %i\n",direction);
				} else fin=1;
			}
			
			if(direction==3){
				if(j1+T<M){
					for(i=0;i<T;i++){
						mat[i1][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
					printf("direction final : %i\n",direction);
				} else fin=1;
			}
			
			if(direction==4){
				if(i1+T<N && j1+T<M){
					for(i=0;i<T;i++){
						mat[i1+i][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
					printf("direction final : %i\n",direction);
				} else fin=1;
			}
			
			if(direction==5){
				if(i1+T<N){
					for(i=0;i<T;i++){
						mat[i1+i][j1]=mot[i];
					}
					fin=1;
					fin2=1;
					printf("direction final : %i\n",direction);
				} else fin=1;
			}
			
			if(direction==6){
				if(i1+T<N && j1-T>=0){
					for(i=0;i<T;i++){
						mat[i1+i][j1-i]=mot[i];
					}
					fin=1;
					fin2=1;
					printf("direction final : %i\n",direction);
				} else fin=1;
			}
			
			if(direction==7){
				if(j1-T>=0){
					for(i=0;i<T;i++){
						mat[i1][j1-i]=mot[i];
					}
					fin=1;
					fin2=1;
					printf("direction final : %i\n",direction);
				} else fin=1;
			}
			
			if(direction==8){
				if(i1-T>=0 && j1-T>=0){
					for(i=0;i<=T;i++){
						mat[i1-i][j1-i]=mot[i];
					}
					fin=1;
					fin2=1;
					printf("direction final : %i\n",direction);
				} else fin=1;
			}
		}
		fin=0;
		direction=direction+1;
		if(direction==9) direction=1;
		printf("direction++\n");
	}
}
	


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
	
	


void premier_mot(char*mot){
	

	
	int i1,j1,i,j,T;
	i1=rand()%N;
	j1=rand()%M;
	
	int sens = rand()%2+1;
	if(sens==1) inversion(mot);
	
	int direction = rand()%8+1;

	insert_premier(mot,i1,j1,direction);

}

int verification(char*mot,char*trouver){

	int taille=strlen(mot);
	int i=0;
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
	
	if(condi=1){
		for(i=taille;i<0;i--){ 
			if(mot[i]!=trouver[i]) return 0;
		}
	} else return 1;
	return 1;
}
	

int main(){
	int taille;
	int deb1,deb2,fin1,fin2;	
	char a;
	
	char* mot="bonjour";
	char* trouver;
	srand(time(NULL));
	
	init_matrice();
	
	premier_mot(mot);
	afficher_matrice();

	

	
	
	do{
	printf("veuillez saisir l'adresse du DEBUT en commencent par le numéro de ligne puis le numéro de colonne : ");
	scanf("%i%i",&deb1,&deb2);
	}while(deb1>=15||deb2>=15||deb1<0||deb2<0);

	
	do{
	printf("veuillez saisir l'adresse de FIN en commencent par le numéro de ligne puis le numéro de colonne  : ");
	scanf("%i%i",&fin1,&fin2);
	}while(fin1>=15||fin2>=15||fin1<0||fin2<0);


	trouver=mot_trouver(deb1,deb2,fin1,fin2);

	printf("\n");
	
	printf("%s",trouver);
	printf("\n");
	if(verification(mot,trouver)==1) printf("bien joué, vous avez trouvé un mot");
	else printf("looser ce n'est pas le bon mot \n");
	
}

