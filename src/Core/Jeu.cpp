#include "Core/Jeu.hpp"

Jeu::Jeu(int largeur, int hauteur) : joueur(nullptr), plateau(largeur, hauteur), marchand(), xJoueur(0), yJoueur(0) {}

Jeu::~Jeu() {}

bool Jeu::deplacerJoueur(int x, int y) {
    // to be implemented
    return true;
}

void Jeu::afficherPlateau(){
    plateau.afficher();
}