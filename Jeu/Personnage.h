#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

class Personnage
{
	public: 
	Personnage();
	Personnage(int difficulte);
	Personnage(int difficulte,int boss);
	Personnage(int difficulte,int boss,int final);
	void recevoirdegats(int nbdegats);
	int recuppdv();
	void prendrebandage(int soin,int nbband);
	void recevoirrelique(int relique);
	void perdrerelique(int relique);
	void ameliorerpv();
	bool possederelique(int relique) const;
	void ameliorerdegat();
	void attaquer(Personnage &cible);
	void actuetat(int difficulte);
	int donneretat();
	void afficherpv() const;
	void afficherrelique() const;
	void afficherdegat() const;
	void afficheretat() const;
	private:
	int m_pdv;
	int m_pdvmax;
	int m_etat;
	int m_degat;
	int m_relique[8];
};

#endif