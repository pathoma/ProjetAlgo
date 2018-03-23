#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"direction.h"

extern t_direction dir_inverse(t_direction direction){
	for(int i=0;i<4;i++)
	{
		direction=dir_suivant(direction);
	}
	return direction;
}
extern t_direction dir_suivant(t_direction direction){

	if(direction==NO)
	{	
		direction = N;
	}
	else
	{
		direction++;
	}
	return direction;
}

extern t_direction dir_precedent(t_direction direction){

	if (direction==N)
	{
		direction=NO;
	}
	else
	{
		direction--;
	}
	return direction;
}

extern void dir_pas_suivant(int x, int y ,int nbpas,t_direction dir,int *px,int *py){

	*px=x;
	*py=y;
	switch (dir)
	{
		case N:
			*px-=nbpas;
			break;
		case NE:
			*px-=nbpas;
			*py+=nbpas;
			break;
		case E:
			*py+=nbpas;
			break;
		case SE:
			*px+=nbpas;
			*py+=nbpas;
			break;
		case S:
			*px+=nbpas;
			break;
		case SO:
			*py-=nbpas;
			*px+=nbpas;
		  break;
		case O:
			*py-=nbpas;
		  break;
		case NO:
			py-=nbpas;
			px-=nbpas;
			break;
		default:
			fprintf(stderr, "direction inconnue\n");
			exit(0);
			break;
	}	

}

extern t_direction dir_convert_to_direc(int x){
	t_direction direc;
	switch (x)
	{
		case 1:
			direc= N;
			break;
		case 2:
			direc= NE;
			break;
		case 3:
			direc= E;
			break;
		case 4:
			direc= SE;
			break;
		case 5:
			direc= S;
			break;
		case 6:
			direc= SO;
		  break;
		case 7:
			direc= O;
		  break;
		default:
			direc= NO;
			break;
	}	
	return direc;
}
extern int dir_convert_to_int(t_direction x){
	int direc;
	switch (x)
	{
		case N:
			direc= 1;
			break;
		case NE:
			direc= 2;
			break;
		case E:
			direc= 3;
			break;
		case SE:
			direc= 4;
			break;
		case S:
			direc= 5;
			break;
		case SO:
			direc= 6;
		  break;
		case O:
			direc= 7;
		  break;
		default:
			direc= 8;
			break;
	}	
	return direc;
}

extern char * dir_affiche(t_direction direction){

return(nom_direc[direction]);

}


