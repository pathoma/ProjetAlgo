#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"mot.h"
#include"outil.h"
#include"matrice.h"



char* inversion(char*mot);
int verification(char*mot,char*trouver);
void remplire_liste();
int afficher_liste();
int saisie();
char* mot_trouver(int i1,int j1,int i2,int j2,mat_t mat);
void ajout_mot(char * mot);
void remplissage(mat_t mat);
int transfert();