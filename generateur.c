#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"premier_saisie.h"
#include"mot_mat.h"
#include"mot.h"

#define N 15
#define M 15
char mat[N][M];


const char LIBRE ='0';
mot_mat_t PlacerMot(mot_mat_t motmis);

int coord_valides(int x, int y){

	return (x>=0 && y>=0 && x<N && y<M);

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
t_direction inserer(char * mot,int i,int j,t_direction direction){
	
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
	int i1=7,j1=6;
	t_direction direc=inserer( "bonjour", i1,j1,E);
	char * motaenvoyer="bonjour";
	
	mot_mat_t mot =creer_mot_mat(i1,j1,motaenvoyer, direc);
	PlacerMot(mot);

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

mot_mat_t premier_mot(char* mot){

	int i1,j1;
	srand(time(NULL));
	i1=rand()%N;
	j1=rand()%M;
	
	int direction = rand()%8+1;

	
	direction=insert_premier_mot(mot, i1, j1, direction);
	//char * motaenvoyer=mot;
	mot_mat_t mon_mot=creer_mot_mat(i1,j1,mot,dir_convert_to_direc(direction-1));
	return mon_mot;
}

int parcours_libre(int coordX,int coordY,t_direction direction)
{ 
	fprintf(stderr,"entrer dans parcours_libre avec les coordonnées : X= %i,Y=%i et la direction %s\n",coordX,coordY,dir_affiche(direction));
	
	dir_pas_suivant(coordX, coordY ,1 , direction, &coordX, &coordY);
	int nbprochainelettre = 0;
	char lettre='0';
	while (lettre == '0' && coord_valides(coordX, coordY)== 1)
	{
		//fprintf(stderr,"la valeur de la matrice est egale a  %c en X=%i et y=%i\n",mat[coordX][coordY],coordX,coordY);
		if(mat[coordX][coordY]=='0') //case libre
		{
				nbprochainelettre++;
		}
		else{
			lettre=mat[coordX][coordY];
		}
		//coordX += compteur1;
		//coordY += compteur2;	
		dir_pas_suivant(coordX, coordY ,1 , direction, &coordX, &coordY);
	}
	fprintf(stderr," a la fin de parcours_libre il renvoie %i \n",nbprochainelettre);
	return nbprochainelettre;
}

mot_mat_t Placerlibre(void)
{
	t_direction dir;
	int taille_max;
	fprintf(stderr,"pour toutes les cases\n");
	for (int i=0;i<N;i++)
	{
		taille_max=0;
		t_direction dir=dir_aleatoire();
		t_direction dir_final;
		for (int j=0;j<N;j++)
		{
		taille_max=0;
		dir=dir_aleatoire();
			fprintf(stderr,"pour la cases i: %i j: %i \n",i,j);
			for(int d=1;d<9;d++)
			{
				if(taille_max<parcours_libre(i,j,dir))
				{
				taille_max=parcours_libre(i,j,dir);
				dir_final=dir;
				}
				fprintf(stderr,"on est en %s la taille max est : %i\n",dir_affiche(dir),taille_max );
				dir=dir_suivant(dir);
				d++;
			}
			fprintf(stderr,"on regarde la taille max \n");
			fprintf(stderr,"verification de l'endroit avec i=%i et j=%i parcourlibre= %i avec la direction : %s\n",i,j,parcours_libre(i,j,dir_final),dir_affiche(dir_final));
			while(taille_max>2)
			{
				for (int t=0;t<nbmot; t++)
				{
					if(taille_mot(t)==taille_max)
					{
						char * mot=recup_mot(t); 
						inserer(mot,i,j,dir_final);
						mot_mat_t mon_mot=creer_mot_mat(i,j,mot,dir_final);
						fprintf(stderr,"le mot %s en coord: i=%i et j=%i ",recup_mot(i),i,j) ;
						fprintf(stderr,"on insert le mot dans la matrice \n");
						return mon_mot;	
					}
				}
				taille_max--;
			}
		}
	}

}

mot_mat_t PlacerMot(mot_mat_t motmis)
{
	int taille_motmis=strlen(motmis.mot);
	int tour =0;
	int compteur =0;
	int commencement= rand()%15;
	//int commencement= 0;
	int tailleavantlettre=0;
	t_direction direction=dir_aleatoire();
	
	do	
	{	
	//pour tout les mots de la liste
		for (int i=commencement;i<nbmot; i++)
		{
			char * motrecup=recup_mot(i);
			tailleavantlettre=0;
			printf("\n %s ", motrecup);

			//pour toutes les lettres du mot de la liste
			for (int j=0;j<taille_mot(i); j++)
			{
				//pour toutes les lettres du mot en paramètres (mot deja dans la matrice)
				for (int a=0;a<taille_motmis;a++)
				{
					if(motrecup[j] == motmis.mot[a])
					{
						fprintf(stderr, " motmis : %s ; motrecup:%s \n",motmis.mot,motrecup); 
						fprintf(stderr, "lettre de motmis : %c : lettre du motrecup:%c \n",motmis.mot[a],motrecup[j]); 
						compteur =0;
						do{	
							int coord2X;
							int coord2Y;
							dir_pas_suivant(motmis.colonne,motmis.ligne,a,motmis.dir,&coord2X,&coord2Y);
							fprintf(stderr, "avant parcourslibre X : %i Y : %i \n",motmis.colonne,motmis.ligne);
							fprintf(stderr, "\ncoord2X : %i coord2Y : %i , direction :%s \n",coord2X,coord2Y,dir_affiche(motmis.dir));
							// si on a la place pour mettre le mot
								//fprintf(stderr,"les coordonnées sont valides : \n");
								fprintf(stderr, "la taille du mot = %i et la tailleavantlettre=%i \n",taille_mot(i),tailleavantlettre);
								if(parcours_libre(coord2X,coord2Y,direction)>(taille_mot(i)-tailleavantlettre) && parcours_libre(coord2X,coord2Y,dir_inverse(direction))>=tailleavantlettre)
								{
									fprintf(stderr,"lettre: %c \n", motmis.mot[tailleavantlettre+1] );
									fprintf(stderr," avantlettre: %i X:%i, Y:%i,direction:%s \n",tailleavantlettre,motmis.colonne,motmis.ligne,dir_affiche(direction));
								
									//si les coordonnées (coord2X,coord2Y) sont valides
									if(coord_valides(coord2X,coord2Y))
									{
									// on va dans la direction inverse de direction
									// nombre de pas = tailleavantlettre
									int x, y;
									dir_pas_suivant(coord2X, coord2Y, tailleavantlettre, dir_inverse(direction), &x, &y);
									
										fprintf(stderr, " on place le mot en X:%i, Y%i, direction:%s \n",x,y,dir_affiche(direction));
								
										// on insere mot_recup à partir de (x,y) dans la direction direction
										inserer(motrecup, x,y,direction);
										supprime_mot(i);
										compteur = 8;
										printf("\n");
										mot_mat_t mon_mot=creer_mot_mat(x,y,motrecup,direction);
										return mon_mot;	
									}
									else{ 
									fprintf(stderr,"on ne peut pas le mettre dans des coordonnées valides direction %s:\n",dir_affiche(direction) );
								direction=dir_suivant(direction);
								compteur++;
								}
							}
							else { 
								/* on n'a pas réussi à poser le mot dans la direction 'direction', on essaye avec la suivante */
								fprintf(stderr, "pas la place pour %s dans la direction %s !\n", motrecup, dir_affiche(direction));
								direction=dir_suivant(direction);
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
}

int main(){
		
	lire_fichier();
	init_matrice();
	
	mot_mat_t monmot=premier_mot(alea_mot());

	 monmot=PlacerMot(monmot);
	 monmot=PlacerMot(monmot);
	 monmot=PlacerMot(monmot);
	 monmot=PlacerMot(monmot);
	 	 monmot=PlacerMot(monmot);
	 	 	 monmot=PlacerMot(monmot);
	 	 	 	 monmot=PlacerMot(monmot);
	 	 	 	 	 monmot=PlacerMot(monmot);
	 	 	 	 	 	 monmot=PlacerMot(monmot);
	
	afficher_matrice();
 	
}

