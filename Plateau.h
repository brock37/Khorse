#ifndef PLATEAU_H
#define PLATEAU_H


#include "Case.h"
#include "constantes.h"
#include "vector"
using namespace std;
class Plateau
{
   public:
      /** Default constructor */
      Plateau();
      /** Default destructor */
      virtual ~Plateau();
      void initialiser();
      void afficher();
      //char afficherCase(int x, int y);
		Case& getCase(int index);
		Case& getCase(Coordonnes pos);
		void changerCase(int i, int j, char type);
		Coordonnes caseDapres(Coordonnes pion, unsigned int avancement);
   
   protected:
   private:
		std::vector<Case> m_plateau;

};

#endif // PLATEAU_H
