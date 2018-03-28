#ifndef _MOT_H_
#define _MOT_H_

extern char *tableauMot[50];
extern int nbmot;
 

extern void lire_fichier(void);
extern void lire_tableau_mots(void);
extern char * recup_mot(int i);
extern void supprime_mot(int i);
extern int taille_mot(int i);
extern  int alea_mot(void);
#endif
