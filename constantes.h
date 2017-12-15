#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>

//#include <boost/multi_array.hpp>
//#include "Case.h"

//typedef boost::multi_array<Case, 2> mon_array;

enum Couleur{ROUGE=0, VERT=1, JAUNE=2 , BLEU=3};
enum Choix{RIEN=0, AVANCER=1, SORTIR=2};
typedef std::pair<int, int> Coordonnes;
/*typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x;
    int y;
};*/

#endif // CONSTANTES_H_INCLUDED
