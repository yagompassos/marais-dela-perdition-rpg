#include "Items/PotionSoin.hpp"
#include "Entities/Personnage.hpp"
#include "Core/icones.hpp"
#include <iostream>

PotionSoin::PotionSoin() : Objet("Potion de Soin", 2){}

void PotionSoin::utiliser(Personnage* hero) {
    hero->curer(5);
}

void PotionSoin::afficher() {
    std::cout << Icone::POTION;
}