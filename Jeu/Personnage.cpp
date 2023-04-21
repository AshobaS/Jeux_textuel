#include <iostream>
#include "Personnage.h"



void Personnage::recevoirdegats(int nbdegats)
{
	m_pdv = m_pdv - nbdegats;
	if (m_pdv < 0)
		m_pdv = 0;
}

int Personnage::recuppdv()
{
		int x;
    return x = m_pdv;
}

void Personnage::prendrebandage(int soin, int nbband)
{
	int i;
	for(i = 0; i < nbband;i++)
		m_pdv = m_pdv + soin;
	if(m_pdv > m_pdvmax)
		m_pdv = m_pdvmax;
}


void Personnage::recevoirrelique(int relique)
{
	m_relique[relique] = 1;
}

void Personnage::ameliorerpv()
{
	m_pdv = m_pdv + 2;
	m_pdvmax = m_pdvmax + 2;
}

void Personnage::ameliorerdegat()
{
	m_degat = m_degat + 1;
}

void Personnage::attaquer(Personnage &cible)
{
	cible.recevoirdegats(m_degat);
}

Personnage::Personnage()
{
	m_pdv = 15;
	m_pdvmax = 15;
	m_degat = 3;
	m_etat = 0;
	int i;
	for(i = 0; i < 8; i++)
		m_relique[i] = 0;
}

Personnage::Personnage(int difficulte)
{
	if(difficulte == 0)
	{
		m_pdv = 6;
		m_degat = 2;
	}
	else
	{
		m_pdv = 8;
		m_degat = 3;
	}
}

Personnage::Personnage(int difficulte, int boss)
{
	if(difficulte == 0)
	{
		m_pdv = 10;
		m_degat = 3;
	}
	else
	{
		m_pdv = 12;
		m_degat = 4;
	}	
}

Personnage::Personnage(int difficulte, int boss, int final)
{
	if(difficulte == 0)
	{
		m_pdv = 13;
		m_degat = 4;
	}
	else
	{
		m_pdv = 16;
		m_degat = 5;
	}	
}

void Personnage::afficherpv() const
{
	std::cout << m_pdv;
}

void Personnage::afficherrelique() const
{
	std::cout << "Vous avez les reliques: ";
	int i;
	for(i = 0; i < 8; i++)
	{
		if(m_relique[i] == 1)
		{
			std::cout << i << " ";
		}
	}
	std::cout << "\n";
}

void Personnage::afficherdegat() const
{
	std::cout << m_degat << "\n";
}

void Personnage::actuetat(int difficulte)
{
	if(m_pdv < m_pdvmax)
		m_etat = 1;
	int limite;
	if(difficulte == 0)
		limite = 2;
	else
		limite = 4;
	if(m_pdv < limite)
		m_etat = 2;
}

void Personnage::afficheretat() const
{
	if(m_etat == 0)
		std::cout << "Normal \n";
	if(m_etat == 1)
		std::cout << "Fatigué : 50% de perdre 1 pv si action \n";
	if(m_etat == 2)
		std::cout << "Critique : action impossible \n";
}

int Personnage::donneretat()
{
	int etat;
	etat = m_etat;
	return etat;
}

bool Personnage::possederelique(int relique) const
{
	return m_relique[relique] == 1;
}

void Personnage::perdrerelique(int relique)
{
	m_relique[relique] = 0;
}