#include "Entities/Guerrier.hpp"
#include "Entities/Ennemi.hpp"

//                              vm frc dex cha gld
Guerrier::Guerrier() : Personnage(30, 28, 3, 8, 3) {}

void Guerrier::attaqueBasique(Ennemi* e) {
    e->recevoirDegats(7);
}