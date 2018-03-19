#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"direction.h"

extern t_direction inverse_direc(t_direction direction){
	for(int i=0;i<4;i++)
	{
		direction=suivant(direction);
	}
	return direction;
}
extern t_direction suivant(t_direction direction){

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

extern t_direction precedent(t_direction direction){

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

