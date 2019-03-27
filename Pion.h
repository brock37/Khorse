#ifndef PION_H
#define PION_H

#include "constantes.h"
#include "Case.h"
class Case;

class Pion
{
	public:
		/** Default constructor */
      Pion(Couleur couleur, int nPion);
		Pion(Pion &copy);
	   Pion& operator=(Pion const& copie);
	   /** Default destructor */
	   ~Pion();
      void deplacer();
      void goToXY(Coordonnes coord);
      void goToXY(int x, int y);
      void memoireCaseSol(Case& sol);
      void sortir(){m_dansLeBox = false; m_caseCourante++;}
      void rentrer();

      bool estRentrer(){return m_dansLeBox;}
      Coordonnes getCoord(){return m_position;}
      char getMemoireSol(){return m_solCase;}
      int getCaseCourante(){return m_caseCourante;}
      int getX(){return m_position.first;}
      int getY(){return m_position.second;}
      Couleur getCouleur(){return m_couleurPion;}
      char getLettre(){return m_lettre;}

   protected:
   private:
      int m_caseCourante;
      int m_nPion;
      Couleur m_couleurPion;
      Coordonnes m_position;
      char m_solCase;
      bool m_dansLeBox;
      bool m_arriver;
      char m_lettre;
};

#endif // PION_H
