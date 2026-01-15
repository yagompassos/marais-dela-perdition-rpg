#include "Entities/Gobelin.hpp"
#include "Entities/Personnage.hpp"
#include "Core/icones.hpp"
#include <iostream>

Gobelin::Gobelin() : Ennemi("Goblin", 12, 15, 5, true) {}

void Gobelin::attaquer(Personnage* hero){
    hero->recevoirDegats(4);
}

void Gobelin::afficher() {
    std::cout << Icone::GOBLIN;
}