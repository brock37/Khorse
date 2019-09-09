

#include "constantes.h"
#include "Pion.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Jeu.h"

using namespace std;

int main()
{

    /* initialize random */
    srand (time(NULL));

    cout << "Jeu des petits chevaux" << endl;
	system("sleep 1");

    Jeu game;
    //Plateau& plateauJeu= game.getPlateau();
    game.jouerPartie();

    return 0;
}
