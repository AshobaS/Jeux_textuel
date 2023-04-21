#ifndef DEF_FONCTIONS
#define DEF_FONCTIONS

void afficher_histoire();

void afficher_regles();

void menu();

int** creerile(int difficulte);

void initile(int difficulte,int** ile);

void affichercase(int valeurcase);

void afficherile(int difficulte,int** ile);

Personnage jeucombat(int difficulte, int* combat, Personnage joueur);

Personnage jeucase(int** ile,int difficulte, int* actuel, int* combat,int* epreuve,Personnage joueur);

Personnage recompense(Personnage joueur, int difficulte);

void listerelique();

Personnage jeuepreuve(int* epreuve, Personnage joueur);

Personnage pendu(int* epreuve,Personnage joueur);

Personnage plusmoins(int* epreuve, Personnage joueur);

Personnage jeucondition(Personnage joueur);

Personnage bossfin(int difficulte,int* combat,int* epreuve, Personnage joueur);

void actioncase(Personnage joueur,int** carte,int difficulte,int* actuel,int** ile);

void deplacement(int difficulte,int** carte,int** ile,int* actuel);

#endif
