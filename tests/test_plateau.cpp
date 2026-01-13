#include <iostream>
#include <string>
#include <vector>
#include "Entities/Guerrier.hpp"
#include "Core/Plateau.hpp"
#include "Core/Jeu.hpp"

int main() {
    int op;

    Jeu jeu(10, 10);
    Personnage *hero = nullptr;

    std::cout << "Marais de Perdition" << std::endl;
    std::cout << "Jouer comme:" << std::endl;
    std::cout << "1. Guerrier" << std::endl;
    std::cout << "2. Mage" << std::endl;
    std::cout << "3. Voleur" << std::endl;

    std::cin >> op;
    switch (op) {
        case 1:
            std::cout << "Guerrier!" << std::endl;
            hero = new Guerrier();
            jeu.setJoueur(hero);
            break;
    }

    std::cout << "\033[2J\033[1;1H";

    jeu.afficherPlateau();
    std::cout << std::endl; 
    jeu.deplacerJoueur(1,0);
    jeu.afficherPlateau();
    std::cout << std::endl; 
    if(jeu.deplacerJoueur(15, 9))
        jeu.afficherPlateau();
    else 
        std::cout << "impossible, dehors plateau" << std::endl;
        std::cout << std::endl; 
    jeu.deplacerJoueur(7, 8);
    jeu.afficherPlateau();


    return 0;
}