typedef struct mat_s{
int nbc;
int nbl;
char ** val; 
}mat_t;


extern mat_t creer_matrice(int ligne ,int colonne);
extern void init_matrice(mat_t ma_mat);
extern void affiche_matrice(mat_t ma_mat);
