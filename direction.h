typedef enum 
{
N,NE,E,SE,S,SO,O,NO
}t_direction;

static char nom_direc[8][3] = {"N","NE","E ","SE","S ","SO","O ","NO"};

extern t_direction inverse_direc(t_direction direction);
extern t_direction suivant(t_direction direction);
extern t_direction precedent(t_direction direction);
