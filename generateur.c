#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"mot.h"

#define N 15
#define M 15
char mat[N][M];
char mot[100];
char trouver[20];

int PlacerMot(int coordX,int coordY, char * motmis);

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


void inserer(int i1,int j1,int direction,int T){
	
	int fin=0;
	int fin2=0;
	int i,j;
	
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
				} else fin=1;
			}
			
			if(direction==2){
				if(i1-T>=0 && j1+T<M){
					for(i=0;i<T;i++){
						mat[i1-i][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==3){
				if(j1+T<M){
					for(i=0;i<T;i++){
						mat[i1][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==4){
				if(i1+T<N && j1+T<M){
					for(i=0;i<T;i++){
						mat[i1+i][j1+i]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==5){
				if(i1+T<N){
					for(i=0;i<T;i++){
						mat[i1+i][j1]=mot[i];
					}
					fin=1;
					fin2=1;
				} else fin=1;
			}
			
			if(direction==6){
				if(i1+T<N && j1-T>=0){
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
		printf("direction++\n");
	}
}
	


int mot_trouver(int i1,int j1,int i2,int j2){
	
	int i;
	int taille;
	

	if(i1==i2&&j1<j2){              	//horizontal à l'endroit 3
		
		taille=(j2-j1)+1;
		for(i=0;i<=taille;i++){
			trouver[i]=mat[i1][j1+i];
		}
		return taille;
	}
	
	
	if(i1==i2&&j1>j2){              	//horizontal à l'envers 7
		
		taille=(j1-j2)+1;
		for(i=0;i<=taille;i++){
			trouver[i]=mat[i1][j1-i];
		}
		return taille;
	}
	
	else if(j1==j2&&i1<i2){		//vertical haut bas 5
		taille=(i2-i1)+1;
		for(i=0;i<=taille;i++){
			trouver[i]=mat[i1+i][j1];
		}
		return taille;
	}
	
	else if(j1==j2&&i2<i1){		//vertical bas haut 1
		taille=(i1-i2)+1;
		for(i=0;i<=taille;i++){
			trouver[i]=mat[i1-i][j1];
		}
		return taille;
	}

	else if(i2>i1&&j2>j1){		//diagonal bas droite 4
		taille=(i2-i1)+1;
		for(i=0;i<=taille;i++){
			trouver[i]=mat[i1+i][j1+i];
		}
		return taille;
	}

	else if(i1>i2&&j1>j2){		//diagonal haut gauche 8
		taille=(i1-i2)+1;
		for(i=0;i<=taille;i++){
			trouver[i]=mat[i1-i][j1-i];
		}
		return taille;
	}
	
	else if(i2>i1&&j1>j2){		//diagonal bas gauche 6
		taille=(i2-i1)+1;
		for(i=0;i<=taille;i++){
			trouver[i]=mat[i1+i][j1-i];
		}
		return taille;
	}

	else if(i1>i2&&j2>j1){		//diagonal haut droit 2
		taille=(i1-i2)+1;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1-i][j1+i];
		}
		return taille;
	}
	
}
	
	


void premier_mot(){
	

	
	int i1,j1,i,j,T;
	i1=rand()%N;
	j1=rand()%M;
	
	int sens = rand()%2+1;
	if(sens==1) inversion();
	
	int direction = rand()%8+1;
	T=strlen(mot);
	
	
	printf("T : %i \n",T);
	inserer(i1,j1,direction,T);
	char * motaenvoyer=mot;
	PlacerMot(i1,j1,motaenvoyer);
}
int parcours_libre(int coordX,int coordY,int direction)
{
	int nbprochainelettre =0;
	int compteur1=0;
	int compteur2=0;
	switch (direction)
	{
	case 1:
		compteur2=-1;
		break;
	case 2:
		compteur1=1;
		compteur2=-1;
		break;
	case 3:
		compteur1=1;
		break;
	case 4:
		compteur1=1;
		compteur2=1;
		break;
	case 5:
		compteur2=1;
		break;
	case 6:
		compteur1=-1;
		compteur2=1;
	  break;
	  case 7:
	  	  compteur1=-1;
		compteur2= 0;
	  break;
	default:
		compteur1=-1;
		compteur2=-1;
		break;
	}
	coordX += compteur1;
	coordY += compteur2;

	char lettre='0';
	while (lettre == '0' && coordX<15 && coordX>0 && coordY<15  && coordY>0)
	{
		if(mat[coordX+compteur1][coordY+compteur2]=='0')
		{
				nbprochainelettre++;
				//lettre= mat[coordX+compteur][coordY+compteur2];
		}
		else{
			lettre=mat[coordX+compteur1][coordY+compteur2];
		}
		coordX += compteur1;
		coordY += compteur2;	
	}
	
	return nbprochainelettre;
}

int PlacerMot(int coordX,int coordY, char * motmis)
{	/*mot[0]='b';
	mot[1]='a';
	mot[2]='l';
	mot[3]='l';
	mot[4]='e';*/
	printf("enter dans placer mot : %s #\n",motmis);
	int taille_motmis=strlen(motmis);
	int tour =0;
	int compteur =0;
	int commencement= rand()%15;
	int tailleavantlettre=0;
	int direction=rand()%8+1;
	int directinverse=direction+4%8;
	do	
	{	
		for (int i=commencement;i<nbmot; i++)
		{
			char * motrecup=recup_mot(i);
			tailleavantlettre=0;
			
			for (int j=0;j<taille_mot(i); j++)
			{
				printf("%s : %s \n",motmis, motrecup);
				for (int a=0;a<taille_motmis;a++)
				{
					if(motrecup[j]==motmis[a])
					{
						do{	
							if(parcours_libre(coordX,coordY,direction)>(taille_mot(i)-tailleavantlettre) && parcours_libre(coordX,coordY,directinverse)>(taille_mot(i)-(taille_mot(i)-tailleavantlettre)))
							{
								for (int x=0; x<taille_mot(i);x++)
								{
									mot[x]=motrecup[x];
								}
								switch (direction)
								{
								case 1:
									coordY+=tailleavantlettre;
									break;
								case 2:
									coordX+=tailleavantlettre;
									coordY-=tailleavantlettre;
									break;
								case 3:
									coordX-=tailleavantlettre;
									break;
								case 4:
									coordX-=tailleavantlettre;
									coordY-=tailleavantlettre;
									break;
								case 5:
									coordY-=tailleavantlettre;
									break;
								case 6:
									coordX-=tailleavantlettre;
									coordY+=tailleavantlettre;
								  break;
								  case 7:
									coordX+=tailleavantlettre;
								  break;
								default:
									coordX+=tailleavantlettre;
									coordY+=tailleavantlettre;
									break;
								}	
								inserer(coordX,coordY,direction,taille_mot(i));
								compteur =8;
								printf("\n");	
							return 0;
							}
							else /* on n'a pas réussi à poser le mot dans la direction 'direction', on essaye avec la suivante */
							{
								if(direction==8)
								{
									direction=1;
								}
								else
									direction++;
									directinverse=direction+4%8;
									compteur++;
					
							}
						}while(compteur<8);
				
					}
				}
				tailleavantlettre++;
			}
		}
		commencement =0;
		tour++;
	}while(tour!=1);
	printf("\n");
	return 1;
}

int main(){
	int taille;
	int deb1,deb2,fin1,fin2;	
	char a;
	
	mot[0]='b';
	mot[1]='o';
	mot[2]='n';
	mot[3]='j';
	mot[4]='o';
	mot[5]='u';
	mot[6]='r';

	srand(time(NULL));
	
	lire_fichier();
	init_matrice();
	premier_mot();
	afficher_matrice();



	
	/*
	do{
	printf("veuillez saisir l'adresse du DEBUT en commencent par le numéro de ligne puis le numéro de colonne : ");
	scanf("%i%i",&deb1,&deb2);
	}while(deb1>N||deb1>M||deb2>N||deb2>M||deb1<0||deb1<0||deb2<0||deb2<0);

	
	do{
	printf("veuillez saisir l'adresse de FIN en commencent par le numéro de ligne puis le numéro de colonne  : ");
	scanf("%i%i",&fin1,&fin2);
	}while(fin1>N||fin1>M||fin2>N||fin2>M||fin1<0||fin1<0||fin2<0||fin2<0);


	taille=mot_trouver(deb1,deb2,fin1,fin2);
	
	printf("\n");
	for(int i=0;i<taille;i++){
		a=trouver[i];
		printf("%c",a);
	}
	printf("\n");
	*/
}

