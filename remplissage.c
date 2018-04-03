#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define N 15
#define M 15
char mat[N][M];
char mot[100];
char trouver[20];


void init_matrice(void){
	int i;
	int j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			mat[i][j]='0';
		}
	}
	mat[0][0]='B';
	mat[1][0]='O';
	mat[2][0]='N';
	mat[3][0]='J';	
	mat[4][0]='O';
	mat[5][0]='U';
	mat[6][0]='R';
	mat[1][14]='J';
}




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

/*
void remplissage(){
	int i,j;
	int nombre;
	int lettre;  
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSYUV"; 	
	srand(time(NULL));
   
	for(i=0;i<N;i++){
	   	for(j=0;j<M;j++){
	   	   	if(mat[i][j]=='0'){
				lettre =rand()% 21; // generation du nombre
				printf("%i ",lettre);
				mat[i][j]= alphabet[lettre];
		
			}
	   	}
	}
}
*/

void remplissage(){
	int i,j;
	int frec;
	int lettre;  
	char alphabet1[] = "EAISNRTOLU";   	 //10 première lettre les plus utilisées
	char alphabet2[] = "DCMPGBVHF";	   	 //tout le reste
	char alphabet3[] = "QYXJKWZ";	   	 //lettre d'une fréquence inférieur à 1%
	srand(time(NULL));
   
	for(i=0;i<N;i++){
	   	for(j=0;j<M;j++){
	   	   	if(mat[i][j]=='0'){
				frec=rand()%3;
				if(frec!=0){
					lettre =rand()% 9;
					printf("%i ",lettre);
					mat[i][j]= alphabet1[lettre];
				} else {
					frec=rand()%3;
					if(frec!=0){
						lettre =rand()% 8;
						printf("%i ",lettre);
						mat[i][j]= alphabet2[lettre];
					} else {	
						lettre =rand()% 6;
						printf("%i ",lettre);
						mat[i][j]= alphabet3[lettre];
					}
				}		
			}
	   	}
	}
}


int main(){

	
	init_matrice();
	
	afficher_matrice();
	remplissage();
	afficher_matrice();

}