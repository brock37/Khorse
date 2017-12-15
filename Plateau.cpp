#include "Plateau.h"

Plateau::Plateau()
{

  initialiser();
  std::cout << "Plateau initialiser" << std::endl;
}

Plateau::~Plateau()
{
}

void Plateau::initialiser()
{
   std::cout << "Init Table de jeu" << std::endl;
   std::ifstream fichier("plateau.txt", std::ios::in);
   char c;

        for(int i(0); i < 15; i++ )
        {
            for(int j(0); j < 15; j++ )
            {

                fichier >> c;

					Case casePlateau(c,i,j);
					m_plateau.push_back( casePlateau);
            }
        }
        if (fichier.eof())
        std::cout << "Fin fichier" << std::endl;

    fichier.close();
}

void Plateau::afficher()
{
    for(int i(0); i < 15; i++ )
    {
        for(int j(0); j < 15; j++ )
            std::cout << m_plateau[j+i*15].getType() << " " ;

        std::cout << std::endl;
    }

}

char Plateau::afficherCase(int i, int j)
{
    return m_plateau[j+i*15].getType() ;
}

Case& Plateau::getCase(int index)
{
  return m_plateau[index];
}

Case& Plateau::getCase(Coordonnes pos)
{
	return m_plateau[pos.first + pos.second*15];
}

void Plateau::changerCase(int i, int j, char type)
{
   m_plateau[i+j*15].setType(type);
}

Coordonnes Plateau::caseDapres(Coordonnes pion, unsigned int avancement)
{
    //Definis la case suivante a patir de la position du pion sur le plateau
    //Commence a la ligne de la sortue du cheval rouge puis dans le sens du jeu
    Coordonnes prochaineCase=std::pair<int, int>(pion.first,pion.second);
    if( avancement < 55)
    {
        if( pion.first == 6 && (pion.second > 8 && pion.second < 14))          {prochaineCase.second--;}
        else if( pion.first == 6 && pion.second == 8)    {prochaineCase.first--;}
        else if( (pion.first > 0 && pion.first < 6)  && pion.second == 8)    {prochaineCase.first--;}
        else if( pion.first == 0 && pion.second == 8)    {prochaineCase.second--;}
        else if( pion.first == 0 && pion.second > 6)     {prochaineCase.second--;}
        else if( pion.first == 0 && pion.second == 6)    {prochaineCase.first++;}
        else if( pion.first < 6 && pion.second == 6)     {prochaineCase.first++;}
        else if( pion.first == 6 && pion.second == 6)    {prochaineCase.second--;}
        else if( pion.first == 6 && pion.second > 0)     {prochaineCase.second--;}
        else if( pion.first == 6 && pion.second == 0)    {prochaineCase.first++;}
        else if( pion.first < 8 && pion.second == 0)     {prochaineCase.first++;}
        else if( pion.first == 8 && pion.second == 0)    {prochaineCase.second++;}
        else if( pion.first == 8 && pion.second < 6)     {prochaineCase.second++;}
        else if( pion.first == 8 && pion.second == 6)    {prochaineCase.first++;}
        else if( pion.first < 14 && pion.second == 6)    {prochaineCase.first++;}
        else if( pion.first == 14 && pion.second == 6)   {prochaineCase.second++;}
        else if( pion.first == 14 && pion.second < 8)    {prochaineCase.second++;}
        else if( pion.first == 14 && pion.second == 8)   {prochaineCase.first--;}
        else if( pion.first > 8 && pion.second == 8)     {prochaineCase.first--;}
        else if( pion.first == 8 && pion.second == 8)    {prochaineCase.second++;}
        else if( pion.first == 8 && pion.second < 14)    {prochaineCase.second++;}
        else if( pion.first == 8 && pion.second == 14)   {prochaineCase.first--;}
        else if( pion.first > 6 && pion.second == 14)    {prochaineCase.first--;}
    }
    else
    {
        if( pion.first == 7 && pion.second > 7)        { prochaineCase.second--;}
        else if( pion.first == 7 && pion.second < 7)    { prochaineCase.second++;}
        else if( pion.first > 7 && pion.second == 7)    { prochaineCase.first--;}
        else if( pion.first < 7 && pion.second == 7)   { prochaineCase.first++;}
    }

    std::cout <<"Acctuelle: " << pion.first << " " << pion.second << std::endl;
    std::cout <<"Suivante: " << prochaineCase.first << " " << prochaineCase.second << std::endl;

 
 // 
  return prochaineCase;
}

