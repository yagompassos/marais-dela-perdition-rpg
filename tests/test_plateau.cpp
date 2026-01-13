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
            break;
    }

    std::cout << "\033[2J\033[1;1H";

    jeu.afficherPlateau();

    // plateau.remplirAleatoirement(3, 2);

    return 0;
}