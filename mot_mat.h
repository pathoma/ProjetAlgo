
#include"direction.h"
typedef struct mot_mat_s{
	int colonne;
	int ligne;
	char * mot;
	t_direction dir; 
}mot_mat_t;

extern mot_mat_t creer_mot_mat(int colonne,int ligne,char * mot,t_direction direc);
