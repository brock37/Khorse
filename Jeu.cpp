#include "Jeu.h"

Jeu::Jeu(): m_plateau()
{
	 //unsigned int nombrePion=0;

	//Initialiser le plateau
	//m_plateau= Plateau();
	//m_plateau.initialiser();

	//Recuperer parametre de la partie
	std::cout << "Avec combien de pion voulez-vous jouer? " ;
   m_nombrePion= 4;//cin >> nombrePion;
   std::cout << "Avec combien de joueur voulez-vous jouer? " ;
   m_nombreJoueur= 1;//cin >> nombreAdversaire;

	//Creer les joueurs et pions necessaires
    m_joueur.push_back(new Joueur(&m_plateau,m_nombrePion, ROUGE));
    m_joueur.push_back(new Joueur(&m_plateau,m_nombrePion, BLEU));
    m_joueur.push_back(new Joueur(&m_plateau,m_nombrePion, VERT));
    m_joueur.push_back(new Joueur(&m_plateau,m_nombrePion, JAUNE));


}

Jeu::~Jeu()
{
	 std::cout << "Desrtruction des Joueurs" << std::endl;
    std::vector<Joueur*>::iterator it;
    for(it =m_joueur.begin(); it != m_joueur.end(); it++)
		delete *it;
}

void Jeu::jouerPartie()
{
	int tourJoueur=0;
   bool gagne= false;
	int waiting=0;
  Joueur* joueurActuel= NULL;

  system("sleep 1");

	do
	{
    joueurActuel= getJoueur(tourJoueur);

		system("clear");
    std::cout << "Tour du Joueur " << joueurActuel->getLettre() << std::endl;

		m_plateau.afficher();
		jouerTour(tourJoueur);


		std::cin >> waiting;
		system("clear");


		std::cout << "Etat du plateau a  la fin du tour" <<std::endl;

		m_plateau.afficher();
		std::cin >> waiting;

    //Pour chaque pion du joueurs
    //Verifier si il sont arriver
    //si oui gagne = true

    gagne= true;
    for(int i= 0; i < m_nombrePion; i++)
    {
      if(joueurActuel->getPionPtr(i)->estArriver() == false)
      {
        gagne= false;
      }
    }

		if(tourJoueur < getNombreJoueur()-1)    {tourJoueur++;}
		else                                {tourJoueur=0;}


		//system("clear");



	}while(!gagne);

  char end;
  m_plateau.afficher();
  std::cout << "Le Joueur " << joueurActuel->getLettre() << " a gagné" << std::endl;
  cin >> end;

}

void Jeu::jouerTour(int joueur)
{
	unsigned int numPion=0;
	int retour=0;
	Choix choixJoueur= RIEN;
	Joueur* joueurActuel= getJoueur(joueur);
	Coordonnes caseSuivante=std::pair<int, int>(0,0);
	Pion* pion=NULL;
	
	joueurActuel->afficherEtatJoueur();
	
	int resDe= joueurActuel->lancerde();
	int nombreDeCase= 0;
	
	if( joueurActuel->estUneIA())    //Si le joueur est une ia
	{
		if(resDe == 6 && joueurActuel->estPartit() == false)
		{

		}
		else if(resDe == 6 && joueurActuel->estPartit() == true)
		{

		}
	}
	else 		//Joueur Humain
	{/*
		//On propose le choix de l'action suivant le resultat du de
		if(resDe == 6 || resDe == 1 )
		{
			choixJoueur= joueurActuel->choixAction();
		}
		else if( joueurActuel->estPartit())   		//Resultat autre que 6 ou 1
		{
			choixJoueur= AVANCER;
		}

		//Si une action possible
		if( choixJoueur != RIEN)
		{
			numPion= joueurActuel->choixPionADeplacer();
			pion= joueurActuel->getPionPtr(numPion);
		}
*/
    pion = joueurActuel->choixJoueur(resDe, choixJoueur);
		//On agit en fontion du choix de l'action
		if(choixJoueur == AVANCER && !pion->estRentrer() && pion->getCaseCourante() < 62)
		{
			m_plateau.getCase(pion->getCoord()).quitterCase( pion->getMemoireSol());
			//Pour chaque case a avancer
			for(nombreDeCase= resDe; nombreDeCase > 0; nombreDeCase--)
			{
				//REcupere les coordonnes de la prochaine case
				caseSuivante= m_plateau.caseDapres( pion->getCoord(), pion->getCaseCourante());

        //Si l'avancement et = 54 (en bas de la ligne droite de fin
        //On regarde le resultat du dé pour savoir si il est egal au num de la case
        if(pion->getCaseCourante() >= 55 && pion->getCaseCourante() <= 61 )
        {
            //std::cout << "ResDe= " << resDe << " , " << (int)m_plateau.getCase( caseSuivante).getType() - (int)'0' << std::endl;
            if(m_plateau.getCase( caseSuivante).getType() == 'X' && resDe == 6)
            {
              std::cout << "Le pion est arrivé" << std::endl;
              pion->arriver();
            }
            else if(resDe != (int)m_plateau.getCase( caseSuivante).getType() - (int)'0')
            {
                std::cout << "On avance pas" << std::endl;
                break;
            }
            nombreDeCase = 0;
        }


        //Sinon on avance normalement
				//Si la case et occuper
				if( occupationCase( caseSuivante))
				{
					Pion* occupant= m_plateau.getCase( caseSuivante).getPtrPion();
					//Se bloque si pion de la meme couleur
					if(occupant->getCouleur() == pion->getCouleur())
					{
						retour= -3;
						break;
					}
					else//Si couleur differente on le mange
					{
						std::cout << "Pion manger" << std::endl;
						manger(occupant);
					}
				}


        pion->memoireCaseSol(m_plateau.getCase(caseSuivante));
				pion->goToXY( caseSuivante);
				pion->deplacer();
				retour= 1;

        if( pion->getCaseCourante() == 62)
        {
          break;
        }

			}
		}
		else if(choixJoueur == SORTIR)
		{
			retour= joueurActuel->sortirCheval( numPion, m_plateau);
		}
		else
		{
			std::cout << "Aucune Action Possible" << std::endl;
		}
		if(choixJoueur != RIEN)
		{
			m_plateau.getCase(pion->getCoord()).occuperCase(pion, joueurActuel->getLettre());
		}
		retourAction(retour);
	}


	std::cout << "Fin du tour!" <<std::endl;

}

bool Jeu::gameOver()
{
	return true;
}


void Jeu::retourAction(int retour)
{
	switch(retour)
	{
		case 0: std::cout << "Aucun retour" << std::endl; break;
		case 1: std::cout << "Le pion avance" << std::endl; break;
		case 2: std::cout << "Le pion est sortie" << std::endl; break;
		case -1: std::cout << "Le pion est encore dans l'enclos" << std::endl; break;
		case -2: std::cout << "Le pion n'existe pas" << std::endl; break;
		case -3: std::cout << "Le pion est bloquer" << std::endl; break;
		case -4: std::cout << "Le pion est deja sortie" << std::endl; break;
		default : std::cout << "Erreur de retour" << std::endl; break;
	}
}

bool Jeu::occupationCase(Coordonnes n)
{
	if(m_plateau.getCase(n).estOccuper())
		return true;
	else
		return false;
}

void Jeu::manger(Pion* occupant)
{
	//On met en remet en place le sol sur le plateau
	m_plateau.getCase(occupant->getCoord()).quitterCase( occupant->getMemoireSol());
	occupant->rentrer();
	//On replace le pion sur le plateau
	m_plateau.getCase(occupant->getCoord()).setType(occupant->getLettre());
}
