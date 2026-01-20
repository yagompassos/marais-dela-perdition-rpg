#include "Core/Plateau.hpp"
#include "Core/Case.hpp"
#include "Core/Des.hpp"
#include "Entities/Gobelin.hpp"
#include "Entities/Orc.hpp"
#include "Entities/Dragon.hpp"
#include "Items/PotionSoin.hpp"
#include "Items/Bouclier.hpp"
#include "Items/Epee.hpp"
#include "Items/Parchemin.hpp"
#include "Core/icones.hpp"
#include <iostream>

// Constructeur
Plateau::Plateau(int largeur, int hauteur): largeur(largeur), hauteur(hauteur) {
    int tirage1, tirage2;
    grille.resize(largeur);
    for (int x = 0; x < largeur; x++) {
        grille[x].resize(hauteur);
        for (int y = 0; y < hauteur; y++) { // Cases du heros 
            if (x==0 && y==0)
                grille[x][y] = Case();
            else if (x==largeur-1 && y==hauteur-1) { // CASE DU DRAGON
                Ennemi *drg = new Dragon();
                grille[x][y] = Case(drg); 
            } else {
                tirage1 = Des::D10();
                if (tirage1<=3) {
                    grille[x][y] = Case();
                } else if (tirage1>3 && tirage1<=5) { // case de ennemi
                    tirage2 = Des::D10();
                    Ennemi *e;
                    if (tirage2 <=6)
                        e = new Gobelin();
                    else
                        e = new Orc();
                    grille[x][y] = Case(e);
                } else if (tirage1>5 && tirage1<=7) { // case avec objet
                    Objet *obj;
                    tirage2 = Des::D10();
                    if (tirage2 <=3)
                        obj = new PotionSoin();
                    else if (tirage2>3 && tirage2 <=6)
                        obj = new Bouclier();
                    else if (tirage2>6 && tirage2 <=8)
                        obj = new Epee();
                    else if (tirage2>8 && tirage2 <=10)
                        obj = new Parchemin();
                    grille[x][y] = Case(obj);
                } else if (tirage1 >7 && tirage1<=8) { // case avec gold
                    tirage2 = Des::D4();
                    grille[x][y] = Case(tirage2);
                } else {                            // case vide
                    grille[x][y] = Case();
                }
            }
        }
    }
}

Plateau::~Plateau(){}

int Plateau::getLargeur() { return largeur; }
int Plateau::getHauteur() { return hauteur; }

void Plateau::afficher(int xJoueur, int yJoueur){
    std::cout << std::endl;
    for (int y=hauteur-1; y>=0; y--) {
        std::cout << "\t";
        for (int x=0; x<largeur; x++) {
            if (x==xJoueur && y==yJoueur)
                std::cout << Icone::GUERRIER;
            else
                grille[x][y].afficher(true);
            std::cout << "    ";
        }
        std::cout << std::endl;
    }
}

bool Plateau::dedantLimits(int x, int y){
    return x >= 0 && x < largeur && y >= 0 && y < hauteur;
}

Case *Plateau::getCase(int x, int y) {
    if (!dedantLimits(x, y))
        throw std::out_of_range("Coordonnées hors plateau");
    return &grille[x][y];
}