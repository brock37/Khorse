#include "Joueur.h"

Joueur::Joueur(Plateau *plateau, int nombrePion, Couleur couleur, bool ia)
{
    m_refPlateau= plateau;
    m_nombrePions= nombrePion;
    m_couleur= couleur;
    m_ia= ia;
    m_dernierLancer= 0;

    for(int i(0); i < m_nombrePions; i++)
    {
        m_pions.push_back( new Pion( m_couleur, i)); //Les pions prennes place lors de la creation

    }

    switch(m_couleur)
    {
        case ROUGE: m_lettre= 'R' ;  break;
        case BLEU:  m_lettre= 'B' ; break;
        case VERT:  m_lettre= 'V' ; break;
        case JAUNE: m_lettre= 'J' ; break;
        default:    std::cout << "Erreur lors de l'associtaion de la couleur au pion." << std::endl;    break;
    }

    placerChevauxDepart( m_refPlateau);

		std::cout << "Joueur " << m_lettre << " creer." << std::endl;
		system("sleep 0.5");
}

Joueur::~Joueur()
{
    std::cout << "Desrtruction des pions" << std::endl;
    std::list<Pion*>::iterator it;
    for(it =m_pions.begin(); it != m_pions.end(); it++)
        delete *it;
}

int Joueur::sortirCheval(int numeroPion, Plateau &plateau)
{
    /** \brief
     *Si le pion demander existe
     *Si le pion demander n'est pas deja sortie
     *
     *On remplace le pion par l'ancienne case
     *On sort le pion
     *On change la poisition du pion
     */
    std::list<Pion*>::iterator it= getPion( numeroPion);

    if( numeroPion > m_nombrePions-1)
        return -2;
    if( !(*it)->estRentrer())
        return -4;

    int indexAncienneCase= (*it)->getX() + (*it)->getY() *15;
    char ancienChar= (*it)->getMemoireSol();

    m_refPlateau->getCase(indexAncienneCase).setType(ancienChar);
    (*it)->sortir();

    for(int i= 0; i < m_nombrePions; i++)
    {
		 std::list<Pion*>::iterator itBis= getPion( i);
		 if((*itBis)->estRentrer())
		 {
			 m_refPlateau->getCase(indexAncienneCase).setType(m_lettre);
		 }
	 }

	 Coordonnes caseSuivante= std::pair<int, int>(0,0);
    switch(m_couleur)
    {
        case ROUGE: caseSuivante= std::pair<int, int>(6,14); break;
        case BLEU:  caseSuivante= std::pair<int, int>(0,6);	break;
        case VERT:	caseSuivante= std::pair<int, int>(8,0); break;
        case JAUNE: caseSuivante= std::pair<int, int>(14,8); break;
        default:    std::cout << "Erreur lors de la sortie du pion." << std::endl;    break;
    }
	(*it)->memoireCaseSol( m_refPlateau->getCase(caseSuivante.first + caseSuivante.second*15));
	(*it)->goToXY(caseSuivante);

    placerCheval(it);
    std::string s = "Le pion n" + to_string((*it)->getNumPion()) + " est sortie";
    std::cout << s  << std::endl;
    return 2;
}



void Joueur::afficherEtatJoueur()
{
/** \brief
*Affiche:le nombre de pions total
*        le nombre de pion sortie
*        le nombre de pion rentree
*        la position de chaque pion
*/
    int nombreChevauxSortie=0;
    int i=0;

    std::cout << "Etat Joueur ";
    switch(m_couleur)
    {
        case ROUGE: std::cout << "ROUGE" << std::endl;   break;
        case BLEU:  std::cout << "BLEU" << std::endl;  break;
        case VERT:  std::cout << "VERT" << std::endl;  break;
        case JAUNE: std::cout << "JAUNE" << std::endl; break;
        default:    std::cout << "Erreur lors de la lecture de la couleur au pion." << std::endl;    break;
    }

    std::cout << "Nombre de pion total:" << m_nombrePions << std::endl;
    std::list<Pion*>::iterator it;
    std::string strSortie;
    for(it= m_pions.begin(); it != m_pions.end(); it++)
    {
        if(!(*it)->estRentrer())
        {
          nombreChevauxSortie++;
          strSortie =strSortie + to_string( (*it)->getNumPion()) + ": " + to_string((*it)->estRentrer());
        }
            
    }

    std::cout << "Nombre de pion sortie:" << nombreChevauxSortie << " Chevaux sorite: " << strSortie << std::endl;
    for(it= m_pions.begin(); it != m_pions.end(); it++)
    {
        std::cout << "position pion n" << i  << ":" << (*it)->getCoord().first << " " << (*it)->getCoord().second << std::endl;
		  std::cout << "Avancement: " << (*it)->getCaseCourante() << std::endl;
		  i++;

    }

    std::cout << "Nombre de pion rentre:" << m_nombrePions - nombreChevauxSortie << std::endl;
}

void Joueur::placerChevauxDepart(Plateau *plateau)
{
    std::list<Pion*>::iterator it;
    for(it= m_pions.begin(); it != m_pions.end(); it++)
    {
        plateau->getCase((*it)->getCoord().first + (*it)->getCoord().second *15).setType(m_lettre);
    }

}

void Joueur::placerCheval(std::list<Pion*>::iterator pion)
{
   m_refPlateau->changerCase((*pion)->getX(),(*pion)->getY(), m_lettre);
}

bool Joueur::estPartit()
{
   std::list<Pion*>::iterator it;
    for(it= m_pions.begin(); it != m_pions.end(); it++)
    {
        if(!(*it)->estRentrer())
            return true;
    }
    return false;
}



int Joueur::lancerde(int dernierLancer)
{
	int res=6;
    //int res= (rand() + dernierLancer) % 6 + 1;
    //std::cout << "Resultat du lance: "<<res << std::endl;
    std::cout << "Entrer la valeur du de : ";
    std::cin >> res;

    return res;
}

std::list< Pion* >::iterator Joueur::getPion(int n)
{
  std::list< Pion* >::iterator it= m_pions.begin();
  std::advance(it, n);
  return it;
}

Pion* Joueur::getPionPtr(int n)
{
	std::list< Pion* >::iterator it= m_pions.begin();
	std::advance(it, n);
  std::cout << "GetPionPtr: " << (*it)->getNumPion() << std::endl;
	return (*it);
}

int Joueur::choixPionADeplacer()
{
	int pionDeplacer=0;

	if( m_nombrePions > 1)
	{
		do
		{
			std::cout << "Quel pion ?(0-" << m_nombrePions - 1 << ")";
			std::cin >> pionDeplacer;
		}while( pionDeplacer < 0 || pionDeplacer >= m_nombrePions);

	}
	else
	{
		pionDeplacer= 0;
	}

	return pionDeplacer;
}

Choix Joueur::choixAction()
{
	int choix=0;
	do
	{
		std::cout << "1.AVANCER / 2.SORTIR" << std::endl;
		std::cin >> choix;
	}while(choix!=AVANCER && choix != SORTIR);

	if(choix== 1)
	{
		return AVANCER;
	}
	else
	{
		return SORTIR;
	}
}

Pion* Joueur::choixJoueur(int de, Choix &choix )
{

  std::vector<int> pionDispo;
  int c = 0, pionDeplacer=0;
  //Choix de l'action
  if(de == 6 || de == 1 )
  {
    do
    {
      std::cout << "1.AVANCER / 2.SORTIR" << std::endl;
      std::cin >> c;
    }while(c!=AVANCER && c != SORTIR);
    if(c== 1)
    {
      choix= AVANCER;
    }
    else
    {
      choix= SORTIR;
    }

  }
  else if( estPartit())   		//Resultat autre que 6 ou 1
  {
    choix= AVANCER;
  }
  else
  {
    choix = RIEN;
  }

//Choix du pion en fonciton de l'action
  //on creer un tableau qui contient l'index des pions dispo en fonction de
  //leur status
  for( std::list< Pion* >::iterator it= m_pions.begin() ; it !=m_pions.end() ; it++)
  {
    if( choix == AVANCER && (*it)->estRentrer() == false )
    {
      std::cout << "Pion n° "<< (*it)->getNumPion() <<" diponible pour avancer" << std::endl;
      pionDispo.push_back( (*it)->getNumPion());
    }
    else if( choix == SORTIR && (*it)->estRentrer() == true )
    {
      std::cout << "Pion n° "<< (*it)->getNumPion() <<" diponible pour sortir" << std::endl;
      pionDispo.push_back( (*it)->getNumPion());
    }
  }

  std::string s= pionDisponible(pionDispo);
  bool indexValide= false;
  do{
    std::cout << "Quel pion ?" << s << ":";
    std::cin >> pionDeplacer;

  for(int j=0 ; j < pionDispo.size(); j++)
  {
    if( pionDeplacer == pionDispo[j])
    {
      indexValide= true;
    }
  }

  }while(!indexValide);
  

  return getPionPtr(pionDeplacer);

}

std::string Joueur::pionDisponible(std::vector<int> const& v)
{
  std::string s= "[ ";

  for(int j=0 ; j < v.size(); j++)
  {
    s += std::to_string(v[j]);
    s+= " , ";
  }

  s.erase( s.end() - 3, s.end());
  s += " ]";
  return s;
}
