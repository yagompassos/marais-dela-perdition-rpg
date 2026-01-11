#include "Core/Plateau.hpp"
#include "Core/Case.hpp"
#include "Core/Random.hpp"
#include "Entities/Gobelin.hpp"
#include "Items/PotionSoin.hpp"
#include <iostream>

// Plateau::Plateau(int largeur, int hauteur): largeur(largeur), hauteur(hauteur) {
//     grille.resize(hauteur);
//     for (int y = 0; y < hauteur; y++) {
//         grille[y].resize(largeur);
//         for (int x = 0; x < largeur; x++) {
//             grille[y][x] = Case();
//         }
//     }
// }

// Constructeur
Plateau::Plateau(int largeur, int hauteur): largeur(largeur), hauteur(hauteur) {
    grille.resize(hauteur);
    for (int y = 0; y < hauteur; y++) {
        grille[y].resize(largeur);
        for (int x = 0; x < largeur; x++) {
            if (y==0 && x==0 || y== hauteur-1 && x == largeur-1)
                grille[y][x] = Case(); // Cases du heros et du dragon
            else {
                int tirage = Random::entier(1, 100);
                if (tirage<=30) {
                    grille[y][x] = Case();
                } else if (tirage>30 && tirage<=50) {
                    Gobelin *e = new Gobelin();
                    grille[y][x] = Case(e);
                } else if (tirage>50 && tirage<=70) {
                    PotionSoin *o = new PotionSoin();
                    grille[y][x] = Case(o);
                } else if (tirage >70 && tirage<=80) {
                    grille[y][x] = Case(2);
                } else {
                    grille[y][x] = Case();
                }
            }
        }
    }
}

Plateau::~Plateau(){}

void Plateau::afficher(){
    for (int y=hauteur-1; y>=0; y--) {
        for (int x=0; x<largeur; x++) {
            grille[y][x].afficher();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Plateau::remplirAleatoirement(int quantiteEnnemi, int quantiteObjets) {
    int totalAAjouter = quantiteEnnemi + quantiteObjets;
    std::vector<int> tirageY = Random::entiersDistincts(1, largeur, totalAAjouter);
    std::vector<int> tirageX = Random::entiersDistincts(1, hauteur, totalAAjouter);

    std::cout << "Tiragem do eixo Y: " ;
    for (int i=0; i<tirageY.size(); i++)
        std::cout << tirageY[i] << " ";

    std::cout << std::endl << "Tiragem do eixo X: " ;
    for (int i=0; i<tirageX.size(); i++)
        std::cout << tirageX[i] << " ";

    
    for (int i=1; i<=quantiteEnnemi; i++) {
        // grille[tirageX[i]][tirageY[i]].setEnnemi();
    }
}