#include <iostream>
#include <stdlib.h>
#include "Personnage.h"
using namespace std;

void afficher_histoire()
{
	cout << "Nous sommes en l'an 400 de la 4éme ére. Le clan Thalmor est à l'apogée de sa puissance et étend son influence sur une grande part de ce monde. En particulier sur le grand désert de Elsweyr bordé à l'Est par la grande mer. Selon certains témoignages, le clan Thalmor aurait établi une colonie penitenciaire un peu particuliére sur l'une des nombreuses iles inhabitées des côtes d'Elsweyr. \n";
	cout << "En effet cette derniére ne servirait uniquement que comme source de divertissement. Des dizaines de nobles se rassembleraient pour observer ces prisonniers s'entre-tuer. Se tenant tous les 10 ans le grand tournoi voit le dernier survivant ou le premier à se montrer digne completement amnistié et remis en liberté. D'ailleurs il semblerait qu'il ait lieu cette année. \n";
	cout << "Mais bon ce n'est qu'une rumeur, rien de bien serieux. \n";
	cout << "Mais si vous deviez y être confronté, priez pour être du bon côté de la grille \n";
	return;
}

void afficher_regles()
{
	system("clear");
	cout << "Vous êtes sur une île et vous vous déplacer de case en case, chaque case correspondant à un évènement. Il y a une sortie placée aléatoirement sur la carte. Pour pouvoir vous échapper vous devez avoir reussi au moins 2 épreuves et 2 combats. Une fois arrivé à la sortie vous affronterez le boss final. \n";
	cout << "En mode difficile il y a plus de cases, les ennemis sont plus forts et il vous faut avoir réussi 4 combats et 4 épreuves. \n";
	return;
}

void menu()
{
	cout << "0 : Commencer Partie \n";
	cout << "1 : Afficher Régles \n";
	cout << "2 : Quitter \n";
	int choix;
	cin >> choix;
	if(choix == 2)
	{
		system("clear");
		cout << "Merci d'avoir jouer \n";
		exit(EXIT_SUCCESS);
	}
	if(choix == 1)
	{
		afficher_regles();
		menu();
	}
	return;
}

int** creerile(int difficulte)
{
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
	int** ile;
	ile = (int**)malloc(ligne * sizeof(int*));
	int i;
	for(i = 0; i < ligne; i++)
		ile[i] = (int*)malloc(colonne * sizeof(int));
	return ile;
}

void initile(int difficulte,int** ile)
{
	int ligne,colonne;
	int type[5];
	type[0] = 1;
	if (difficulte == 0)
	{
		ligne = 5;
		colonne = 4;
		type[1] = 5;
		type[2] = 5;
		type[3] = 6;
		type[4] = 2;
	}
	else
	{
		ligne = 5;
		colonne = 8;
		type[1] = 10;
		type[2] = 10;
		type[3] = 12;
		type[4] = 6;	
	}
	int i,j,x;
	for(i = 0; i < ligne; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			if((i == 0) && (j == 0))
			{
				ile[0][0] = 5;
			}
			else
			{
				x = rand() % 5;
				while(type[x] == 0)
					x = rand() % 5;
				ile[i][j] = x;
				type[x] = type[x] - 1;	
			}
		}
	}
	return;
}

void affichercase(int valeurcase)
{
	if (valeurcase == 0)
		cout << " S ";
	if (valeurcase == 1)
		cout << " F ";
	if (valeurcase == 2)
		cout << " E ";
	if (valeurcase == 3)
		cout << " C ";
	if (valeurcase == 4)
		cout << " H ";
	if (valeurcase == 5)
		cout << " B ";
	if (valeurcase == 6)
		cout << " X ";
	if (valeurcase == 7)
		cout << " . ";
}


void afficherile(int difficulte,int** ile)
{
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
	system("clear");
	int i,j;
	cout << " B : Entree S: Sortie F: Combat E: Epreuve C: Condition S: Soin X: Joueur \n";
	for(i = 0; i < ligne; i++)
	{
		for(j = 0; j < colonne; j++)
		{
			affichercase(ile[i][j]);
		}
		cout << "\n";
	}
}

void listerelique()
{
	system("clear");
	cout << "Relique 0: Le gant de fermete \n";
	cout << "Ignore les premiers dégats subis à chaque combat \n";
	cout << "Relique 1: Le savoir de l'Erudit \n";
	cout << "Permet de retenter une épreuve ratée \n";
	cout << "Relique 2: Les lunettes du pari\n";
	cout << "Pendant les combats, jouer a deviner les coups adverses \n";
	cout << "Relique 3: La gemme de la seconde chance \n";
	cout << "Permet de revenir à la vie quand vous mourrez \n";
	cout << "Relique 4: La dague percante \n";
	cout << "Les premiers degats que vous infligez à chaque combat sont doublés \n";
	cout << "Relique 5: Le bracelet beni \n";
	cout << "Vous recupérez 5pv à chaque victoire contre un ennemi \n";
	cout << "Relique 6: La cuirasse de vie \n";
	cout << "Augmente vos points de vie de 10 \n";
	cout << "Relique 7: La benediction du Vampire \n";
	cout << "Vous récuperez 1pv chaque fois que vous infligez des dégats \n";
	return;
}


Personnage recompense(Personnage joueur, int difficulte)
{
	system("clear");
	cout << "Recompenses : \n";
	int x;
	int relique[3];
	if(difficulte == 0)
	{
		x = rand() % 101;
		if(x < 90)
		{
			cout << "Vous recuperez 6 points de vie \n";
			joueur.prendrebandage(3, 2);
		}
		x = rand() % 101;	
		if(x < 50)
		{
			cout << "Vous recuperez une amélioration de point de vie \n";
			joueur.ameliorerpv();
		}
		x = rand() % 101;
		if(x < 50)
		{
			cout << "Vous recupérez une amélioration de dégats \n";
			joueur.ameliorerdegat();
		}
		x = rand() % 101;
		if(x < 15)
		{
			cout << "Vous gagnez une relique ! \n";
			listerelique();
			relique[0] = rand() % 8;
			relique[1] = rand() % 8;
			relique[2] = rand() % 8;
			cout << " Vous avez le choix entre ces 3 reliques:\n";
			cout << "0:     Relique " << relique[0] << "\n";
			cout << "1:     Relique " << relique[1] << "\n";
			cout << "2:     Relique " << relique[2] << "\n";
			int numrelique;
			cin >> numrelique;
			joueur.recevoirrelique(relique[numrelique]);
		}
	}
	else
	{
		x = rand() % 101;
		if(x < 90)
		{
			cout << "Vous recuperez 2 points de vie \n";
			joueur.prendrebandage(2, 1);
		}
		x = rand() % 101;	
		if(x < 25)
		{
			cout << "Vous recuperez une amélioration de point de vie \n";
			joueur.ameliorerpv();
		}
		x = rand() % 101;
		if(x < 25)
		{
			cout << "Vous recupérez une amélioration de dégats \n";
			joueur.ameliorerdegat();
		}
		x = rand() % 101;
		if(x < 10)
		{
			cout << "Vous gagnez une relique ! \n";
			listerelique();
			relique[0] = rand() % 8;
			relique[1] = rand() % 8;
			relique[2] = rand() % 8;
			cout << " Vous avez le choix entre les 3 reliques:\n";
			cout << "0:     Relique " << relique[0];
			cout << "1:     Relique " << relique[1];
			cout << "2:     Relique " << relique[2];
			int newrelique;
			cin >> newrelique;
			joueur.recevoirrelique(relique[newrelique]);
			if(relique[newrelique] == 6)
			{
				int i;
				for(i = 0; i < 5; i++)
					joueur.ameliorerpv();
			}
		}
	}
	return joueur;
}



Personnage jeucombat(int difficulte, int* combat, Personnage joueur)
{
	Personnage ennemi;
	if((*combat) == 2)
	{
		system("clear");
		cout << "En arrivant dans cette partie de l'île vous tomber sur un mage qui semble particulièrement dangereux. Au moment ou vous essayer de lui parler, vous le voyait incanter une boule de feu. \n";
		cout << "Le combat commence ! \n";
		ennemi = Personnage(difficulte,0);
	}
	else
	{
		if((*combat) == -1)
		{
			ennemi = Personnage(difficulte,0,0);
		}
		else
		{
			if(((*combat) == 4) && (difficulte == 1))
			{
				system("clear");
				cout << "Vous commencez à sentir une odeur nauséabonde provenir des environs mais vous ne semblez pas pourvoir la localiser. En arrivant dans une plaine vous comprennez d'ou vient cette odeur. Devant vous se dresse un colosse entouré d'une bonne dizaine de corps. On dirait que vous êtes le suivant, Preparez vous !\n";
				ennemi = Personnage(difficulte,0);
			}
			else
			{
				system("clear");
				cout << "Vous tombez nez à nez avec un autre prisonnier qui ne semble pas enclin à vous laissez passer.";
				cout << "Le combat semble inévitable \n";
				ennemi = Personnage(difficulte);
			}
		}
	}

	int pvj,pve;
	pvj = joueur.recuppdv();
	pve = ennemi.recuppdv();
	int fermete,pari,percant;
	fermete = 0;
	pari = 0;
	percant = 0;
	if(joueur.possederelique(0))
		fermete = 1;
	if(joueur.possederelique(2))
		pari = 1;
	if(joueur.possederelique(4))
		percant = 1;
	while((pve > 0) && (pvj > 0))
	{
		cout << "Vos Pv: ";
		cout << pvj;
		cout << "\n";
		cout << "Pv Ennemi: ";
		cout << pve;
		cout << "\n";
		if(pari == 1)
		{
			system("clear");
			cout << "Pari est actif, vous devez deviner le coup de l'adversaire \n";
			cout << "0: Epee \n";
			cout << "1: Arc \n";
			cout << "2: magie \n";
			int choix;
			cin >> choix;
			int enne;
			enne = rand() % 3;
			if(choix == enne)
			{
				cout << "Vous avez correctement devine ! \n";
				joueur.attaquer(ennemi);
				if(joueur.possederelique(7))
					joueur.prendrebandage(1, 1);
				if(percant == 1)
				{
					joueur.attaquer(ennemi);
					percant = 0;
				}
				pve = ennemi.recuppdv();
			}
			else
			{
				cout << "Vous n'avez pas deviné ! \n";
				cout << "Vous ne prenez pas de degats mais vous perdez Pari \n";
				pari = 0;
			}
		}
		else
		{
			cout << "0: Epee \n";
			cout << "1: Arc \n";
			cout << "2: magie \n";
			int choix;
			cin >> choix;
			int enne;
			enne = rand() % 3;
			int gagnant = 3;
			if(choix == enne)
			{
				cout << "Egalite, il ne se passe rien \n";
				gagnant = 3;
			}
			else
			{
				if(choix == 0)
				{
					if(enne == 1)
					{
						gagnant = 0;
					}
					else
					{
						gagnant = 1;
					}
				}
				else
				{
					if(choix == 1)
					{
						if(enne == 0)
						{
							gagnant = 1;
						}
						else
						{
							gagnant = 0;
						}
					}
					else
					{
						if(enne == 0)
						{
							gagnant = 0;
						}
						else
						{
							gagnant = 1;
						}
					}
				}
			}
			if(gagnant == 0)
			{
				cout << "Vous remportez cette manche \n";
				joueur.attaquer(ennemi);
				if(percant == 1)
				{
					percant = 0;
					joueur.attaquer(ennemi);
				}
				if(joueur.possederelique(7))
					joueur.prendrebandage(1, 1);
				pve = ennemi.recuppdv();
			}
			if(gagnant == 1)
			{
				cout << "Vous perdez cette manche \n";
				if(fermete == 0)
				{
					ennemi.attaquer(joueur);
					pvj = joueur.recuppdv();
				}
				else
				{
					fermete = 0;
				}
			}
		}
	}
	if(pvj > 0)
	{
		(*combat) = (*combat) + 1;
		joueur = recompense(joueur,difficulte);
		if(joueur.possederelique(5))
			joueur.prendrebandage(5, 1);
	}
	else
	{
		if(joueur.possederelique(3))
		{
			joueur.prendrebandage(100, 1);
			joueur.perdrerelique(3);
			joueur = jeucombat(difficulte, combat, joueur);
		}
		else
		{
			system("clear");
			cout << "Game Over !";
			exit(EXIT_SUCCESS);
		}
	}
	return joueur;
}


Personnage plusmoins(int* epreuve, Personnage joueur)
{
	system("clear");
	cout << "Vous arrivez dans une petite clairiére qui semble tranquille quand tout à coup vous vous sentez défaillir. A cet instant vous voyer un elfe Thalmor apparaitre dans votre esprit \n";
	cout << "Bienvenue petit prisonnier, tu es tombé dans l'un de nos piéges. Il n'y a qu'une seule solution pour t'échapper, résoudre cette énigme \n";
	cout << "Plus ou moins entre 0 et 100 \n";
	int x = rand() % 101;
	int coup = 10;
	int choix = - 1;
	while((coup >= 0) && (choix != x))
	{
		cout << "Il vous reste " << coup << " essais \n";
		cin >> choix;
		if(choix > x)
			cout << "c'est moins \n";
		if(choix < x)
			cout << "c'est plus \n";
		coup = coup - 1;
	}
	if(choix == x)
	{
		system("clear");
		cout << "Félicitation vous remportez cette épreuve, vous pouvez continuer. \n";
		(*epreuve) = (*epreuve) + 1;
		return joueur;
	}
	else
	{
		if(joueur.possederelique(1))
		{
			system("clear");
			cout << "Vous dépenser le savoir d'érudit pour recommencer l'épreuve \n";
			joueur.perdrerelique(1);
			return plusmoins(epreuve,joueur);
		}
		else
		{
			system("clear");
			cout << "Vous avez échoué pauvre mécréant, alors Souffrez ! \n";
			cout << "Vous perdez 2 point de vie et sortez de l'illusion \n";
			Personnage ennemi;
			ennemi = Personnage(0);
			ennemi.attaquer(joueur);
			int pve = joueur.recuppdv();
			if(pve <= 0)
			{
				if(joueur.possederelique(3))
				{
					cout << "Vous consommer la gemme de la seconde chance \n";
					joueur.prendrebandage(100, 1);
					joueur.perdrerelique(3);
					return joueur;
				}
				else
				{
					system("clear");
					cout << "Lorsque vous vous reveiller la seule chose que vous avez le temps de voir est un autre prisonnier lever son epee \n";
					cout << "Game Over ! \n";
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
	return joueur;
}

Personnage pendu(int* epreuve,Personnage joueur)
{
	system("clear");
	cout << "Vous arrivez dans une petite clairiére qui semble tranquille quand tout à coup vous vous sentez défaillir. A cet instant vous voyer un elfe Thalmor apparaitre dans votre esprit \n";
	cout << "Bienvenue petit prisonnier, tu es tombé dans l'un de nos piéges. Il n'y a qu'une seule solution pour t'échapper, résoudre cette énigme \n";
	cout << "Pendu \n";
	int coup = 15;
	char dico[7][8] = {"explose","amortie","puisque","teindre","fendoir","discret","royaume"};
	char mot[7];
	int x = rand() % 8;
	int i;
	for(i = 0 ; i < 7; i++)
	{
		mot[i] = dico[x][i];
	}
	char trouve[7];
	for(i = 0 ; i < 7; i++)
	{
		trouve[i] = '.';
	}
	int parti = 0;
	while((parti == 0) && (coup > -1))
	{
		char lettre;
		int la = 0;
		cout << "Il vous reste " << coup << " vies \n";
		cout << "Mot: " << trouve << "\n";
		cout << "Lettre: ";
		cin >> lettre;
		for(i = 0 ; i < 7; i++)
		{
			if(mot[i] == lettre)
			{
				la = 1;
				trouve[i] = lettre;
			}
		}
		if(la == 1)
		{
			cout << "La lettre est la \n";
		}
		else
		{
			cout << "La lettre n'est pas la \n";
			coup = coup - 1;
		}
		parti = 1;
		for(i = 0 ; i < 7; i++)
			if(trouve[i] == '.')
				parti = 0;
	}
	if(parti == 1)
	{
		system("clear");
		cout << "Félicitation vous remportez cette épreuve, vous pouvez continuer. \n";
		(*epreuve) = (*epreuve) + 1;
		return joueur;
	}
	else
	{
		if(joueur.possederelique(1))
		{
			cout << "Vous dépenser le savoir d'érudit pour recommencer l'épreuve \n";
			joueur.perdrerelique(1);
			return pendu(epreuve,joueur);
		}
		else
		{
			system("clear");
			cout << "Vous avez échoué pauvre mécréant, alors Souffrez ! \n";
			cout << "Vous perdez 2 point de vie et sortez de l'illusion \n";
			Personnage ennemi;
			ennemi = Personnage(0);
			ennemi.attaquer(joueur);
			int pve = joueur.recuppdv();
			if(pve <= 0)
			{
				if(joueur.possederelique(3))
				{
					cout << "Vous consommer la gemme de la seconde chance \n";
					joueur.prendrebandage(100, 1);
					joueur.perdrerelique(3);
					return joueur;
				}
				else
				{
					system("clear");
					cout << "Lorsque vous vous reveiller la seule chose que vous avez le temps de voir est un autre prisonnier lever son epee \n";
					cout << "Game Over ! \n";
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
	return joueur;
}


Personnage jeuepreuve(int* epreuve, Personnage joueur)
{
	int x;
	x = rand() % 101;
	if(x < 50)
		joueur = plusmoins(epreuve,joueur);
	else
		joueur = pendu(epreuve,joueur);
	return joueur;
}

Personnage jeucondition(Personnage joueur)
{
	int x = rand() %  101;
	system("clear");
	cout << "Vous arrivez face à un immense arbre et vous voyez quelque chose briller au sommet. Voulez vous aller le recupérer ? \n";
	cout << " 1 pour Oui 2 pour Non \n";
	int choix;
	cin >> choix;
	int etat = joueur.donneretat();
	if(choix == 1)
	{
		if(etat == 2)
		{
			cout << "Vous êtes trop blessé pour faire quoi que ce soit, vous abbandonner \n";
			return joueur;
		}
		else
		{
			cout << "Vous arrivez à atteindre l'objet \n";
			if(x <= 40)
			{
				cout << "Vous récupérez 2 bandages sur une branche \n";
				joueur.prendrebandage(3, 2);
			}
			else 
			{
				if ((x > 40) && (x <= 70))
				{
					cout << "Vous récuperez une augmentation de PV \n";
					joueur.ameliorerpv();
				}
				else
				{
					cout << "Vous récuperez une augmentation de dégats \n";
					joueur.ameliorerdegat();
			
				}
			}
		}
	}
	else
	{
		cout << "Vous décider de ne pas tenter le coup \n";
		return joueur;
	}
	return joueur;
}

Personnage bossfin(int difficulte,int* combat,int* epreuve, Personnage joueur)
{
	system("clear");
	cout << "Vous arrivez devant une grille donnant sur le mur d'enceinte gardé par un orc en armure rutilante \n";
	cout << "Voyons si vous êtes dignes \n";
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
	int digne = 0;
	if(((*combat) >= limitecomb) && ((*epreuve) >= limiteep))
	{
		digne = 1;
	}
	if(digne == 0)
	{
		system("clear");
		cout << "Malheureusement vous n'êtes pas digne de vous confronter au champion revenez quand vous aurez fait vos preuves \n";
	}
	else
	{
		system("clear");
		cout << "Bien vous avez été digne du dernier obstacle, avancez, terrassez le champion et vous aurez votre liberté \n";
		(*combat) = -1;
		joueur = jeucombat(difficulte, combat, joueur);
		cout << "Mesdames et Messieurs \n";
		cout << "Il semblerait que nous ayons un champion ! \n";
		cout << "Passe ces grilles et tu retrouveras ta liberté \n";
		exit(EXIT_SUCCESS);
	}
	return joueur;
}

Personnage jeucase(int** ile,int difficulte, int* actuel, int* combat,int* epreuve,Personnage joueur)
{
	int ligne = actuel[0];
	int colonne = actuel[1];
	if(ile[ligne][colonne] == 1)
		joueur = jeucombat(difficulte,combat,joueur);
	if(ile[ligne][colonne] == 2)
		joueur = jeuepreuve(epreuve,joueur);
	if(ile[ligne][colonne] == 3)
		joueur = jeucondition(joueur);
	if(ile[ligne][colonne] == 4)
	{
		system("clear");
		cout << "Vous tomber sur une fontaine, vous en profiter pour boire un peu, vous récuperez deux points de vie \n";
		joueur.prendrebandage(2, 1);
	}
	if(ile[ligne][colonne] == 10)
	{
		system("clear");
		cout << "Case deja visitée \n";
	}
	if(ile[ligne][colonne] == 0)
		joueur = bossfin(difficulte,combat,epreuve,joueur);
	return joueur;
}

void deplacement(int difficulte,int** carte,int** ile,int* actuel)
{
	afficherile(difficulte, carte);
	int ligne = actuel[0];
	int colonne = actuel[1];
	carte[ligne][colonne] = ile[ligne][colonne];
	int retient;
	retient = ile[ligne][colonne];
	ile[ligne][colonne] = 10;
	int maxligne,maxcolonne;
	if(difficulte == 0)
	{
		maxcolonne = 3;
		maxligne = 4;
	}
	else
	{
		maxcolonne = 7;
		maxligne = 4;
	}
	cout << "Déplacement: ";
	cout << "5: Haut, 0: Bas, 1: Gauche, 3: Droite \n";
	cout << "Possible: \n";
	if(ligne == 0)
	{
		if(colonne == 0)
		{
			cout << "3: Droite \n";
			cout << "0: Bas \n";
		}
		else
		{
			if(colonne == maxcolonne)
			{
				cout << "1: Gauche \n";
				cout << "0: Bas \n";
			}
			else
			{
				cout << "1: Gauche \n";
				cout << "3: Droite \n";
				cout << "0: Bas \n";
			}
		}
	}
	else
	{
		if(ligne == maxligne)
		{
			if(colonne == 0)
			{
				cout << "5: Haut \n";
				cout << "3: Droite \n";
			}
			else
			{
				if(colonne == maxcolonne)
				{
					cout << "5: Haut \n";
					cout << "1: Gauche \n";
				}
				else
				{
					cout << "5: Haut \n";
					cout << "1: Gauche \n";
					cout << "3: Droite \n";
				}
			}
		}
		else
		{
			if(colonne == 0)
			{
				cout << "5: Haut \n";
				cout << "3: Droite \n";
				cout << "0 : Bas \n";
			}
			else
			{
				if(colonne == maxcolonne)
				{
					cout << "5: Haut \n";
					cout << "1: Gauche \n";
					cout << "0: Bas \n";
				}
				else
				{
					cout << "5: Haut \n";
					cout << "1: Gauche \n";
					cout << "3: Droite \n";
					cout << "0: Bas \n";
				}
			}
		}
	}
	int choix;
	cin >> choix;
	if(ligne == 0)
	{
		if(colonne == 0)
		{
			if((choix != 3) && (choix != 0))
			{
				cout << "Erreur choix impossible";
				carte[ligne][colonne] = 6;
				ile[ligne][colonne] = retient;
				deplacement(difficulte, carte, ile, actuel);
			}
		}
		else
		{
			if(colonne == maxcolonne)
			{
				if((choix != 1) && (choix != 0))
				{
					cout << "Erreur choix impossible";
					carte[ligne][colonne] = 6;
					ile[ligne][colonne] = retient;
					deplacement(difficulte, carte, ile, actuel);
				}
			}
			else
			{
				if((choix != 0) && (choix != 1) && (choix != 3))
				{
					cout << "Erreur choix impossible";
					carte[ligne][colonne] = 6;
					ile[ligne][colonne] = retient;
					deplacement(difficulte, carte, ile, actuel);
				}
			}
		}
	}
	else
	{
		if(ligne == maxligne)
		{
			if(colonne == 0)
			{
				if((choix != 3) && (choix != 5))
				{
					cout << "Erreur choix impossible";
					carte[ligne][colonne] = 6;
					ile[ligne][colonne] = retient;
					deplacement(difficulte, carte, ile, actuel);
				}
			}
			else
			{
				if(colonne == maxcolonne)
				{
					if((choix != 1) && (choix != 5))
					{
						cout << "Erreur choix impossible";
						carte[ligne][colonne] = 6;
						ile[ligne][colonne] = retient;
						deplacement(difficulte, carte, ile, actuel);
					}
				}
				else
				{
					if((choix != 5) && (choix != 1) && (choix != 3))
					{
						cout << "Erreur choix impossible";
						carte[ligne][colonne] = 6;
						ile[ligne][colonne] = retient;
						deplacement(difficulte, carte, ile, actuel);
					}
				}
			}
		}
		else
		{
			if(colonne == 0)
			{
				if((choix != 5) && (choix != 3) && (choix != 0))
				{
					cout << "Erreur choix impossible";
					carte[ligne][colonne] = 6;
					ile[ligne][colonne] = retient;
					deplacement(difficulte, carte, ile, actuel);
				}
			}
			else
			{
				if(colonne == maxcolonne)
				{
					if((choix != 5) && (choix != 1) && (choix != 0))
					{
						cout << "Erreur choix impossible";
						carte[ligne][colonne] = 6;
						ile[ligne][colonne] = retient;
						deplacement(difficulte, carte, ile, actuel);
					}
				}
				else
				{
					if((choix != 0) && (choix != 1) && (choix != 3) && (choix != 5))
					{
						cout << "Erreur choix impossible";
						carte[ligne][colonne] = 6;
						ile[ligne][colonne] = retient;
						deplacement(difficulte, carte, ile, actuel);
					}
				}
			}
		}
	}
	if(choix == 0)
	{
		actuel[0] = actuel[0] + 1;
	}
	if(choix == 1)
	{
		actuel[1] = actuel[1] - 1;
	}
	if(choix == 3)
	{
		actuel[1] = actuel[1] + 1;
	}
	if(choix == 5)
	{
		actuel[0] = actuel[0] - 1;
	}
	return;
}

void actioncase(Personnage joueur,int** carte,int difficulte,int* actuel,int** ile)
{
	cout << "0: Afficher Equipement \n";
	cout << "1: Afficher carte \n";
	cout << "2: Deplacement \n";
	cout << "3: Quitter Jeu \n";
	int choix;
	cout << "Que voulez vous faire ? ";
	cin >> choix;
	if(choix == 0)
	{
		listerelique();
		joueur.afficherrelique();
		int pv;
		pv = joueur.recuppdv();
		cout << "Pv : " << pv << "\n";
		cout << "Etat : ";
		joueur.afficheretat();
		cout << "Degats : ";
		joueur.afficherdegat();
		actioncase(joueur,carte,difficulte,actuel,ile);
	}
	if(choix == 1)
	{
		afficherile(difficulte,carte);
		actioncase(joueur,carte,difficulte,actuel,ile);
	}
	if(choix == 2)
	{
		deplacement(difficulte,carte,ile,actuel);
	}
	if(choix == 3)
	{
		cout << "Merci d'avoir joué ! \n";
		exit(EXIT_SUCCESS);
	}
}