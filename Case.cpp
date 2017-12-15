#include "Case.h"

Case::Case(char c)
{
    m_type= c;
    m_coord.first= 0;
    m_coord.second= 0;
    m_occuper= false;
    m_pion= NULL;
}

Case::Case(char c, int x, int y)
{
    m_type= c;
    m_coord.first= x;
    m_coord.second= y;
    m_occuper= false;
    m_pion= NULL;
}

Case::Case(const Case& copie)
{
    m_type= copie.m_type;
    m_coord= copie.m_coord;
    m_occuper= copie.m_occuper;
    m_pion= NULL;
}


Case::~Case()
{
    //dtor
}

Case& Case::operator=(const Case& copie)
{
      m_type= copie.m_type;
      m_coord= copie.m_coord;
      return *this;
}

void Case::occuperCase(Pion* ptr, char type)
{
	m_pion= ptr;
	m_occuper= true;
	m_type= type;
}

void Case::quitterCase(char type)
{
	m_pion= NULL;
	m_occuper= false;
	m_type= type;
	
}

Pion* Case::getPtrPion()
{
	if(m_pion != NULL)
	 return m_pion;
	else
	 return NULL;
}
