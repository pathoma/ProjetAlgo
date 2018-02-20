#include<stdio.h>
#include<stdlib.h>


#define D 40
#define N 10
#define M 15

int inversion(char mot[]){
	int i;
	N=strl(mot[]);
	char inverse[];

	for(i=0;i>=N;i++){
		inverse[i]=mot[N-i];
		
	}
	return(inverse);
}




int mot_trouver(int i1,int j1,int i2,int j2,int mat[N][M]){
	
	char mot[20];
	int i;
	int taille;


	if(i1==i2&&j1<j2){              	//horizontal à l'endroit
		
		taille=j2-j1;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1][j1+i];
		}
		return(mot);
	}
	
	
	if(i1==i2&&j1>j2){              	//horizontal à l'envers
		
		taille=j1-j2;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1][j1-i];
		}
		return(mot);
	}
	
	else if(j1==j2&&i1<i2){		//vertical haut bas
		taille=i2-i1;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1+i][j1];
		}
		return(mot);

	}
	
	else if(j1==j2&&i2<i1){		//vertical bas haut
		taille=i1-i2;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1-i][j1];
		}
		return(mot);

	}

	else if(i2>i1&&j2>j1){		//diagonal bas droite
		taille=i2-i1;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1+i][j1+i];
		}
		return(mot);
	}

	else if(i1>i2&&j1>j2){		//diagonal haut gauche
		taille=i1-i2;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1-i][j1-i];
		}
		return(mot);

	}
	
	else if(i2>i1&&j1>j2){		//diagonal bas gauche
		taille=i2-i1;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1+i][j1-i];
		}
		return(mot);
	}

	else if(i1>i2&&j2>j1){		//diagonal haut droit
		taille=i1-i2;
		for(i=0;i<=taille;i++){
			mot[i]=mat[i1-i][j1+i];
		}
		return(mot);
	}
	
}



void main(){
	
	int deb1,deb2,fin1,fin2,id;


	do{
	printf("veuillez saisir le numéro du mot que vous avez trouvé");
	scanf("%i",id);
	}while(id>D);
	
	
	do{
	printf("veuillez saisir l'adresse du DEBUT en commencent par le numéro de ligne puis le numéro de colonne");
	scan("%i%i",deb1,deb2);
	}while(deb1>N||deb1>M||deb2>N||deb2>M||deb1<0||deb1<0||deb2<0||deb2<0);

	
	do{
	printf("veuillez saisir l'adresse de FIN en commencent par le numéro de ligne puis le numéro de colonne");
	scan("%i%i",fin1,fin2);
	}while(fin1>N||fin1>M||fin2>N||fin2>M||fin1<0||fin1<0||fin2<0||fin2<0);
	
	
}