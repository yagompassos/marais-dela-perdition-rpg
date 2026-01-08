#include <iostream>
#include <string>
#include <vector>
#include "Entities/Guerrier.hpp"
#include "Entities/Gobelin.hpp"


int main() {
    int op;

    Personnage *hero = nullptr;
    Gobelin g1;

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

    hero->enricher(15);
    std::cout << hero->getGold() << std::endl;

    std::cout << "HP: " << hero->getVie() << "/" << hero->getVieMax() << std::endl;
    hero->recevoirDegats(21);
    std::cout << "HP: " << hero->getVie() << "/" << hero->getVieMax() << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << g1.getRace() << " " << g1.getVieMax() << " " << g1.getForce() << std::endl;
    g1.attaquer(hero);
    std::cout << "HP: " << hero->getVie() << "/" << hero->getVieMax() << std::endl;

    std::cout << std::endl << std::endl << "On attaque:" << std::endl;

    hero->attaqueBasique(&g1);
    std::cout << g1.getRace() << " vie: " << g1.getVie() << std::endl;
    std::cout << "Is gobelin alive? R: " << g1.estVivant() << std::endl;    
    hero->attaqueBasique(&g1);
    std::cout << g1.getRace() << " vie: " << g1.getVie() << std::endl;
    std::cout << "Is gobelin alive? R: " << g1.estVivant() << std::endl;    

    
    return 0;
}