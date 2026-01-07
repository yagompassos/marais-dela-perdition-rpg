#include "Entities/Personnage.hpp"
#include "Entities/Ennemi.hpp"
#include <iostream>

Personnage::Personnage(){};
Personnage::Personnage(int vm, int forc, int dex, int cha, int gld) : vieMax(vm), vie(vm), force(forc), dexterite(dex), chance(cha), gold(gld) {};
// Personnage::~Personnage(){};

int Personnage::getVieMax() { return vieMax; }
int Personnage::getVie() { return vie; }
int Personnage::getGold() { return gold; }

// to override
void Personnage::attaqueBasique(Ennemi* e){}

void Personnage::recevoirDegats(int degat) {
    if (degat < vie)
        vie -= degat;
    else {
        vie = 0;
        std::cout << "GAME OVER" << std::endl << "You died." << std::endl;
    }
}

void Personnage::ajouterGold(int goldGagne) {
    gold += goldGagne;
}
