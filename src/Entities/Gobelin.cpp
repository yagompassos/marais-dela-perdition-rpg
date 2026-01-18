#include "Entities/Gobelin.hpp"
#include "Entities/Personnage.hpp"
#include "Core/icones.hpp"
#include <iostream>
                            //race    vm frc gld volable
Gobelin::Gobelin() : Ennemi("Goblin", 45, 17, 5, true) {}

void Gobelin::attaquer(Personnage* hero){
    hero->recevoirDegats(force);
}

void Gobelin::afficher() {
    std::cout << Icone::GOBLIN;
}