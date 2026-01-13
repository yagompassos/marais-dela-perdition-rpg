#ifndef JEU_H
#define JEU_H

#include "Core/Plateau.hpp"
#include "Core/Marchand.hpp"

class Personnage;

class Jeu {
private: 
    Personnage *joueur;
    Plateau plateau;
    Marchand marchand;
    int xJoueur;
    int yJoueur;
public:
    Jeu();
    Jeu(int largeur, int hauteur);
    virtual ~Jeu();
    void setJoueur(Personnage* p);
    bool deplacerJoueur(int dx, int dy);
    void afficherPlateau();
};

#endif