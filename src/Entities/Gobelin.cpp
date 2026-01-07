#include "Entities/Gobelin.hpp"
#include "Entities/Personnage.hpp"

Gobelin::Gobelin() : Ennemi("Goblin", 12, 15, 5, true) {}

void Gobelin::attaquer(Personnage* hero){
    hero->recevoirDegats(4);
}