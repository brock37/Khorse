#ifndef JOUEUR_H
#define JOUEUR_H

#include "constantes.h"
#include <list>
#include <vector>
#include "Plateau.h"
#include "Pion.h"

class Joueur
{
	public:
		/** Default constructor */
      Joueur(Plateau *plateau, int nombrePion, Couleur couleur, bool ia= false);
      /** Default destructor */
      ~Joueur();
      
      
      void placerCheval(std::list<Pion*>::iterator pion);
      int sortirCheval(int numeroCheval, Plateau &plateau);
      void placerChevauxDepart(Plateau *plateau);
      
      void afficherEtatJoueur();
      
      bool estPartit();
      bool estUneIA(){return m_ia;}
      
      char getLettre(){return m_lettre;};
      
      Coordonnes caseDapres(Coordonnes pion, unsigned int avancement);
      
      int choixPionADeplacer();
      Choix choixAction();
      int lancerde(int dernierLancer=0);
      
      std::list<Pion*>::iterator getPion(int n);
      Pion* getPionPtr(int n);
      
        




			std::string pionDisponible(std::vector<int>  v);
			Pion* choixJoueur(int de, Choix &choix );


	protected:
   private:
		std::list<Pion*> m_pions;
		int m_nombrePions;
		Couleur m_couleur;
		char m_lettre;
		bool m_ia;
		int m_dernierLancer;
		Plateau* m_refPlateau;
};

#endif // JOUEUR_H
