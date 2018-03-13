#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define N 15
#define M 15
char mat[N][M];
char mot[100];

void inversion(void){
	
	printf("mot : %s \n",mot);
	
	int i,T;
	T=strlen(mot);
	
	char inverse[T];

	for(i=0;i<T;i++){
		inverse[i]=mot[T-1-i];	
	}
	inverse[T] = '\0';
	
	/*for(i=0;i<T;i++){
		mot[i]=inverse[i];
	}*/
	
	strcpy(mot, inverse);
	
	
	printf("inverse : %s \n",inverse);
	printf("mot : %s \n",mot);
	printf("FIN\n");
}



void init_matrice(void){
	int i;
	int j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			mat[i][j]='0';
		}
	}
}

void afficher_matrice(void){
	int i;
	int j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%c  ",mat[i][j]);
		}
		printf("\n");
	}
}

void inserer(int i1,int j1,int direction,int T){
	
	int fin=0;
	int fin2=0;
	int i,j;
	
	printf("début inséré \n");
	
	while(fin2!=1){
		
		while(fin!=1){
			
			if(direction==1){
				if(i1-T>=0){
					for(i=0;i<T;i++){
						mat[i1-i][j1]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==2){
				if(i1-T>=0 && j1+T<=M){
					for(i=0;i<T;i++){
						mat[i1-i][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==3){
				if(j1+T<=M){
					for(i=0;i<T;i++){
						mat[i1][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==4){
				if(i1+T<=N && j1+T<=M){
					for(i=0;i<T;i++){
						mat[i1+i][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==5){
				if(i1+T<=N){
					for(i=0;i<T;i++){
						mat[i1+i][j1]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==6){
				if(i1+T<=N && j1-T>=0){
					for(i=0;i<T;i++){
						mat[i1+i][j1-i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==7){
				if(j1-T>=0){
					for(i=0;i<T;i++){
						mat[i1][j1-i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==8){
				if(i1-T>=0 && j1-T>=0){
					for(i=0;i<=T;i++){
						mat[i1-i][j1-i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
		}
		fin=0;
		direction=direction+1;
		if(direction==9) direction=1;
	}
}
	
	
	
/*void premier_mot(){
	

	
	int i1,j1,i,j,T;
	i1=rand()%N;
	j1=rand()%M;
	
	int sens = rand()%2+1;
	if(sens==1) inversion();
	
	int direction = rand()%8+1;
	T=strlen(mot);
	
	
	printf("T : %i \n",T);
	inserer(i1,j1,direction,T);

}
*/

void premier_mot(){
	

	
	int i1,j1,i,j,T;
	i1=rand()%N;
	j1=rand()%M;
	
	int sens = rand()%2+1;
	if(sens==1) inversion();
	
	int direction = rand()%8;
	T=strlen(mot);
	
	
	printf("T : %i \n",T);
	inserer(i1,j1,direction,T);

}

int main(){
	
	mot[0]='b';
	mot[1]='o';
	mot[2]='n';
	mot[3]='j';
	mot[4]='o';
	mot[5]='u';
	mot[6]='r';

	srand(time(NULL));
	
	init_matrice();
	premier_mot();
	afficher_matrice();
}


/*int main(){
	
	int i1;
	srand(time(NULL));
	
	i1= rand()%2+1;
	printf("\n%i\n",i1);
}
*/