#include"mot_mat.h"

extern mot_mat_t creer_mot_mat(int colonne,int ligne,char * mot,t_direction direc)
{
	mot_mat_t mon_mot_mat;
	mon_mot_mat.ligne=ligne;
	mon_mot_mat.colonne=colonne;
	mon_mot_mat.mot= mot;
	mon_mot_mat.dir=direc;
	return mon_mot_mat;
}

