#include "Pion.h"

Pion::Pion(Couleur couleur, int nPion)
{
    m_nPion= nPion;

    m_caseCourante= -1;

    m_dansLeBox= true;
    
    m_arriver= false;
    
    m_solCase= 'H';

    switch(couleur)
    {
        case ROUGE:
				goToXY(5,14);
				m_couleurPion= ROUGE;
				m_lettre= 'R';
				break;
        case BLEU:
				goToXY(0,5);
				m_couleurPion= BLEU;
				m_lettre= 'B';
				break;
        case VERT:
				goToXY(9,0);
				m_couleurPion= VERT;
				m_lettre= 'V';
				break;
        case JAUNE:
				goToXY(14,9);
				m_couleurPion= JAUNE;
				m_lettre= 'J';
				break;
        default:    std::cout << "Erreur lors du placement des pion." << std::endl;    break;
    }
}

Pion::Pion(Pion& copie)
{
	m_caseCourante= copie.m_caseCourante;
   m_nPion= copie.m_nPion;
   m_couleurPion= copie.m_couleurPion;
   m_position= copie.m_position;
   m_solCase= copie.m_solCase;
   m_dansLeBox= copie.m_dansLeBox;
   m_arriver= copie.m_arriver;
   m_lettre= copie.m_lettre;
}

Pion& Pion::operator=(const Pion& copie)
{
  if(&copie != this)
  {
    m_caseCourante= copie.m_caseCourante;
    m_nPion= copie.m_nPion;
    m_couleurPion= copie.m_couleurPion;
    m_position= copie.m_position;
    m_solCase= copie.m_solCase;
    m_dansLeBox= copie.m_dansLeBox;
    m_arriver= copie.m_arriver;
    m_lettre= copie.m_lettre;
  }
  return *this;
}


Pion::~Pion()
{
    //dtor
}

void Pion::deplacer()   //Fais avancer le pion sur le chemin de la victoire
{
    m_caseCourante++;
}

void Pion::goToXY(Coordonnes coord)    //Deplace virtuelement le pion au coordonees
{
    m_position.first= coord.first;
    m_position.second= coord.second;
}

void Pion::goToXY(int x, int y)
{
    m_position.first= x;
    m_position.second= y;
}

void Pion::memoireCaseSol(Case &sol) //Enregistre le symbole sous le cheval
{
    m_solCase=sol.getType();
}

void Pion::rentrer()
{
	m_caseCourante= -1;
	m_dansLeBox= true;
	switch(m_couleurPion)
    {
        case ROUGE:
				goToXY(5,14);
				break;
        case BLEU:
				goToXY(0,5);
				break;
        case VERT:
				goToXY(9,0);
				break;
        case JAUNE:
				goToXY(14,9);
				break;
        default:    std::cout << "Erreur lors du placement des pion." << std::endl;    break;
    }
}
