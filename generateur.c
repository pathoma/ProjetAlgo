#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"mot.h"
#include"direction.h"
#define N 15
#define M 15
char mat[N][M];
char mot[100];
char trouver[20];
const char LIBRE ='0';
int PlacerMot(int coordX,int coordY, char * motmis,int dirmotmis);

int coord_valides(int x, int y){

	return (x>0 && y>0 && x<N && y<M);

}

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

//inserer mot à partir de (i1, j1) dans la direction direction
//les verification sont faites avant
int inserer(char * mot,int i,int j,int direction){
	
	int fin=0;
	int fin2=0;
	//int i,j;
	int T=strlen(mot);
	
	/*printf("début inséré \n");
	printf("direction : %i , i1 = %i , j1 = %i  \n",direction,i1,j1);*/

	//pour chaque lettre de mot
	for(int l=0; l<T; l++){
	// placer la lettre en i,j
		mat[i][j]=mot[l];
	// se déplacer d'un pas dans la direction  direction
		dir_pas_suivant(i, j , 1, direction, &i, &j);
	}

	return direction;
}
	

void ajoutnonaleatoire(void){
	int i1=13,j1=13;
	inserer( "bonjour", 13,13,7);
	//char * motaenvoyer=mot;
	PlacerMot(i1,j1,mot,dir_convert_to_direc(7));
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
	
	
int insert_premier_mot(char * mot,int i1,int j1,int direction){
	int fin=0;
	int fin2=0;
	int i,j;
	int T=strlen(mot);
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
		return direction;

}

void premier_mot(){
	
	int i1,j1,i,j,T;
	i1=rand()%N;
	j1=rand()%M;
	
	int sens = rand()%2+1;
	if(sens==1) inversion();
	
	int direction = rand()%8+1;
	T=strlen(mot);
	
	
	fprintf(stderr, "T : %i \n",T);
	direction=insert_premier_mot("bonjour", i1, j1, direction);
	//char * motaenvoyer=mot;
	PlacerMot(i1,j1,"bonjour",dir_convert_to_direc(direction));
}
int parcours_libre(int coordX,int coordY,int direction)
{
	int nbprochainelettre =0;
	int compteur1=0;
	int compteur2=0;
	switch (direction)
	{
	case N:
		compteur1=-1;
		break;
	case NE:
		compteur2=1;
		compteur1=-1;
		break;
	case E:
		compteur2=1;
		break;
	case SE:
		compteur2=1;
		compteur1=1;
		break;
	case S:
		compteur1=1;
		break;
	case SO:
		compteur2=-1;
		compteur1=1;
	  break;
	  case O:
	  	  compteur2=-1;
		compteur1= 0;
	  break;
	default:
		compteur2=-1;
		compteur1=-1;
		break;
	}
	coordX += compteur1;
	coordY += compteur2;
	
	

	char lettre='0';
//	while (lettre == '0' && coordX<15 && coordX>0 && coordY<15  && coordY>0)
	while (lettre == LIBRE && coord_valides(coordX, coordY) )
	{
		if(mat[coordX][coordY]==LIBRE) //case libre
		{
				nbprochainelettre++;
				//lettre= mat[coordX+compteur][coordY+compteur2];
		}
		else{
			lettre=mat[coordX][coordY];
		}
		//coordX += compteur1;
		//coordY += compteur2;	
		dir_pas_suivant(coordX, coordY ,1 , direction, &coordX, &coordY);
	}
	
	return nbprochainelettre;
}

int PlacerMot(int coordX,int coordY, char * motmis, int dirmotmis)
{
	int taille_motmis=strlen(motmis);
	int tour =0;
	int compteur =0;
	//int commencement= rand()%15;
	int commencement= 0;
	int tailleavantlettre=0;
	
	//int direc=rand()%8+1;
	//t_direction direction=dir_convert_to_direc(direc);
	
	t_direction direction=dir_aleatoire();
	
	do	
	{	
	//pour tout les mots de la liste
		for (int i=commencement;i<nbmot; i++)
		{
			char * motrecup=recup_mot(i);
			tailleavantlettre=0;
			//pour toutes les lettres du mot de la liste
			for (int j=0;j<taille_mot(i); j++)
			{
				printf("\n %s ", motrecup);
				//pour toutes les lettres du mot en paramètres (mot deja dans la matrice)
				for (int a=0;a<taille_motmis;a++)
				{
					if(motrecup[j] == motmis[a])
					{
						fprintf(stderr, " motmis : %s ; motrecup:%s \n",motmis,motrecup); 
						fprintf(stderr, "lettre de motmis : %c : lettre du motrecup:%c \n",motmis[a],motrecup[j]); 
						compteur =0;
						do{	
							int coord2X;
							int coord2Y;
							dir_pas_suivant(coordX,coordY,a,direction,&coord2X,&coord2Y);
							fprintf(stderr, "\ncoord2X : %i coord2Y : %i\n",coord2X,coord2Y);
						
							// si on a la place pour mettre le mot
							if(parcours_libre(coord2X,coord2Y,direction)>(taille_mot(i)-tailleavantlettre) && parcours_libre(coord2X,coord2Y,dir_inverse(direction))>(taille_mot(i)-(taille_mot(i)-tailleavantlettre)))
							{
								printf("lettre: %c \n", mot[tailleavantlettre] );
								printf(" avantlettre: %i X:%i, Y:%i,direction:%s \n",tailleavantlettre,coordX,coordY,dir_affiche(direction));
								
								// on va dans la direction inverse de direction
								// nombre de pas = tailleavantlettre
								int x, y;
								dir_pas_suivant(coord2X, coord2Y, tailleavantlettre, dir_inverse(direction), &x, &y);
								// si (x,y) sont des coordonnées valides
								if( coord_valides(x,y) )
								{
									fprintf(stderr, " on place le mot en X:%i, Y%i, direction:%s \n",x,y,dir_affiche(direction));
								
									// on insere mot_recup à partir de (x,y) dans la direction direction
									inserer(motrecup, x,y, dir_convert_to_int(direction));
									supprime_mot(i);
									compteur =8;
									printf("\n");	
									return 0;
								}
							}
							else /* on n'a pas réussi à poser le mot dans la direction 'direction', on essaye avec la suivante */
							{
								fprintf(stderr, "pas la place pour %s dans la direction %s !\n", motrecup, dir_affiche(direction));
								direction=dir_suivant(direction);
								compteur++;
					
							}  
						}while(compteur<8);
					}
				tailleavantlettre++;	
				}

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
	
	strcpy(mot, "bonjour");

	srand(time(NULL));
	
	lire_fichier();
	init_matrice();
	
	ajoutnonaleatoire();
	afficher_matrice();
	printf(" \n\n\n%i\n\n\n",parcours_libre(13,13,NO));
	


	
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

