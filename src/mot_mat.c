#include"mot_mat.h"
/**
 * ... Documentation ...
 * \file mot_mat.c
 * \brief mot_mat.c permet de gerer les mot_mat.c
 * \author THOMAS Paul
 * \version 1.0
 * \date 3 avril 2018
*/

/**
 * \fn mot_mat_t creer_mot_mat(int colonne,int ligne,char * mot,t_direction direc)
 * \brief fonction qui créé un mot_mat avec les paramètres donnés
 * \param colonne correspond a la colonne ou le mot commence
 * \param ligne correspond a la ligne ou le mot commence
 * \param mot correspont au mot qui est dans la matrice
 * \param direction correspont la direction du mot dans la matrice
 * \return mot_mat_t une variable qui correspont a un mot dans la matrice
*/
extern mot_mat_t creer_mot_mat(int colonne,int ligne,char * mot,t_direction direc)
{
	mot_mat_t mon_mot_mat;
	mon_mot_mat.ligne=ligne;
	mon_mot_mat.colonne=colonne;
	mon_mot_mat.mot= mot;
	mon_mot_mat.dir=direc;
	return mon_mot_mat;
}

