#include "Core/Plateau.hpp"
#include "Core/Case.hpp"
#include "Core/Random.hpp"
#include "Entities/Gobelin.hpp"
#include "Items/PotionSoin.hpp"
#include <iostream>

// Constructeur
Plateau::Plateau(int largeur, int hauteur): largeur(largeur), hauteur(hauteur) {
    grille.resize(largeur);
    for (int x = 0; x < largeur; x++) {
        grille[x].resize(hauteur);
        for (int y = 0; y < hauteur; y++) {
            if (x==0 && y==0)
                grille[x][y] = Case(); // Cases du heros 
            else if (x==largeur-1 && y==hauteur-1) 
                grille[x][y] = Case(); //CASE DU DRAGON
            else {
                int tirage = Random::entier(1, 100);
                if (tirage<=30) {
                    grille[x][y] = Case();
                } else if (tirage>30 && tirage<=50) {
                    Gobelin *e = new Gobelin();
                    grille[x][y] = Case(e);
                } else if (tirage>50 && tirage<=70) {
                    PotionSoin *o = new PotionSoin();
                    grille[x][y] = Case(o);
                } else if (tirage >70 && tirage<=80) {
                    grille[x][y] = Case(2);
                } else {
                    grille[x][y] = Case();
                }
            }
        }
    }
}

Plateau::~Plateau(){}

int Plateau::getLargeur() { return largeur; }
int Plateau::getHateur() { return hauteur; }

void Plateau::afficher(int xJoueur, int yJoueur){
    for (int y=hauteur-1; y>=0; y--) {
        for (int x=0; x<largeur; x++) {
            if (x==xJoueur && y==yJoueur)
                std::cout << "H";
            else if (x==largeur-1 && y==hauteur-1)
                std::cout << "D";
            else
                grille[x][y].afficher();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

bool Plateau::dedantLimits(int x, int y){
    return x >= 0 && x < largeur && y >= 0 && y < hauteur;
}

Case &Plateau::getCase(int x, int y) {
    if (!dedantLimits(x, y))
        throw std::out_of_range("Coordonnées hors plateau");
    return grille[x][y];
}