#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Personnage.h"
#include "fonctions.h"

int main() 
{
	afficher_histoire();
	std::cout << "Si c'est votre première partie, nous conseillons de lire les régles \n";
	menu();
	int difficulte;
	std::cout << "Choix difficulte: \n";
	std::cout << "0 pour Normal, 1 pour difficile \n";
	std::cin >> difficulte;
	int** ile;
	ile = creerile(difficulte);
	srand(time(NULL));
	initile(difficulte,ile);
	int ligne,colonne;
	if(difficulte == 0)
	{
		colonne = 4;
		ligne = 5;
	}
	else
	{
		colonne = 8;
		ligne = 5;
	}
	int** carte = NULL;
	carte = creerile(difficulte);
  int i,j;
	for(i = 0; i < ligne; i++)
		for(j = 0; j < colonne; j++)
			carte[i][j] = 7;
	Personnage joueur;
	joueur = Personnage();
	int jeu = 1;
	int* actuel;
	actuel = (int*)malloc(2*sizeof(int));
	actuel[0] = 0;
	actuel[1] = 0;
	int a = 0;
	int* nb_combats = &a;
	int b = 0;
	int* nb_epreuves = &b;
	int medepreuve = 0;
	int medcombat = 0;
	while(jeu == 1)
	{
		carte[actuel[0]][actuel[1]] = 6;
		joueur = jeucase(ile,difficulte,actuel,nb_combats,nb_epreuves,joueur);
		int limiteep,limitecomb;
		if(difficulte == 0)
		{
			limiteep = 2;
			limitecomb = 2;
		}
		else
		{
			limiteep = 4;
			limitecomb = 4;
		}
		if(((*nb_combats) >= limitecomb) && (medcombat == 0))
		{
			std::cout << "Vous avez prouvé votre force \n";
			medcombat = 1;
		}
		if(((*nb_epreuves) >= limiteep) && (medepreuve == 0))
		{
			std::cout << "Vous avez prouvé votre intelligence \n";
			medepreuve = 1;
		}
		actioncase(joueur, carte, difficulte,actuel,ile);
	}
}