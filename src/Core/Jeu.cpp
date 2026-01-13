#include "Core/Jeu.hpp"

Jeu::Jeu(int largeur, int hauteur) : joueur(nullptr), plateau(largeur, hauteur), marchand(), xJoueur(0), yJoueur(0) {}

Jeu::~Jeu() {}

void Jeu::afficherPlateau(){
    plateau.afficher(xJoueur, yJoueur);
}

void Jeu::setJoueur(Personnage *p) {
    joueur = p;
}

bool Jeu::deplacerJoueur(int dx, int dy) {
    if (!plateau.dedantLimits(dx, dy))
        return false;
    
    xJoueur = dx;
    yJoueur = dy;
    return true;
}
