typedef enum 
{
N=0,NE,E,SE,S,SO,O,NO
}t_direction;

static char nom_direc[8][3] = {"N","NE","E ","SE","S ","SO","O ","NO"};

extern t_direction dir_inverse(t_direction direction);
extern t_direction dir_suivant(t_direction direction);
extern t_direction dir_precedent(t_direction direction);
extern void dir_pas_suivant(int x, int y ,int nbpas,t_direction dir,int * nx,int * ny);
extern t_direction dir_convert_to_direc(int x);
extern int dir_convert_to_int(t_direction);
extern char * dir_affiche(t_direction direction);
