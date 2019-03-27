#ifndef JEU_H
#define JEU_H

#include <vector>

#include "Plateau.h"
#include "Joueur.h"

class Jeu
{
	public:
	Jeu();
	~Jeu();
	
	void jouerPartie();
	bool gameOver();
	
	Plateau& getPlateau(){return m_plateau;}; 
	Joueur* getJoueur(int i){ return m_joueur[i]; };
	int getNombreJoueur(){return m_nombreJoueur;};
	
	void jouerTour(int joueur);
	
	void retourAction(int retour);
	
	bool occupationCase(Coordonnes n);
	void manger(Pion* occupant);
	
	protected:
	
	private:
	Plateau m_plateau;
	std::vector<Joueur*> m_joueur;
	
	int m_nombreJoueur;
	int m_nombrePion;
	
};


#endif // JEU_H
