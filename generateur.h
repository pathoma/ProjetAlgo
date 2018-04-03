#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"premier_saisie.h"
#include"mot_mat.h"
#include"mot.h"

mot_mat_t PlacerMot(mot_mat_t motmis,mat_t ma_mat);
int coord_valides(int x, int y, mat_t ma_mat);
t_direction inserer(char * mot,int i,int j,t_direction direction, mat_t ma_mat);
mot_mat_t ajoutnonaleatoire(mat_t ma_mat);
int parcours_libre(int coordX,int coordY,t_direction direction,  mat_t ma_mat,int version);
mot_mat_t insert_premier_mot(char * mot,int i1,int j1,t_direction direction,mat_t ma_mat);
mot_mat_t premier_mot(char * mot, mat_t ma_mat);
mot_mat_t Placerlibre(mat_t ma_mat);
mot_mat_t PlacerMot(mot_mat_t motmis, mat_t ma_mat);
void remplir_final(mat_t ma_mat);
