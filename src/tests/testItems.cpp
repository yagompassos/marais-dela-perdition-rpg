#include <iostream>
#include <string>
#include <vector>
#include "Entities/Guerrier.hpp"
#include "Items/PotionSoin.hpp"

int main() {
    int op;

    Personnage *hero = nullptr;
    PotionSoin p1, p2, p3, p4, p5;

    std::cout << "Ile de Perdition" << std::endl;
    std::cout << "Jouer comme:" << std::endl;
    std::cout << "1. Guerrier" << std::endl;
    std::cout << "2. Mage" << std::endl;
    std::cout << "3. Voleur" << std::endl;

    std::cin >> op;
    if (op==1) {
        std::cout << "Guerrier!" << std::endl;
        hero = new Guerrier();
    }

    std::cout << std::endl << std::endl;

    std::cout << p1.getNom() << " " << p1.getPrix() << std::endl;
    hero->ajouterObjet(&p1);
    hero->afficherInventaire();
    hero->ajouterObjet(&p2);
    hero->afficherInventaire();
    hero->ajouterObjet(&p3);
    hero->afficherInventaire();
    hero->ajouterObjet(&p4);
    hero->afficherInventaire();
    hero->ajouterObjet(&p5);
    hero->afficherInventaire();

    // Gotta test Personnage::curer() and PotionSoin::utiliser() methods
    
    return 0;
}