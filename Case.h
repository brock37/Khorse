#ifndef CASE_H
#define CASE_H

#include "constantes.h"
#include <utility>
#include "Pion.h"
class Pion;
typedef std::pair<int, int> Coordonnes;
class Case
{
   public:
      /** Default constructor */
      Case();
      Case(char c='z');
      Case(char c, int x, int y);
      Case( const Case &copie);
      /** Default destructor */
      virtual ~Case();
        
      Case& operator=(Case const& copie);
        
      Coordonnes getCoord(){return m_coord;};
        
      void setType(char n){ m_type= n;};
      char getType(){return m_type;};
        
      void occuper(bool oc){ m_occuper= oc;};
      bool estOccuper(){return m_occuper;};
        
      Pion* getPtrPion();
      void setPtrPion(Pion* ptr){ m_pion= ptr;};
        
      void occuperCase(Pion* ptr, char type);
      void quitterCase(char type);

   protected:
   private:
		char m_type;
		Coordonnes m_coord;
		bool m_occuper;
		Pion* m_pion; 
	
};

#endif // CASE_H
