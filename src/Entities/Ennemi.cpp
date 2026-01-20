#include "Entities/Ennemi.hpp"
#include "Entities/Personnage.hpp"
#include "Core/icones.hpp"
#include <iostream>

Ennemi::Ennemi(){};
Ennemi::Ennemi(std::string race, int vieMax, int force, int recompenseOr, bool volable) : race(race), vieMax(vieMax), vie(vieMax), force(force), recompenseOr(recompenseOr), volable(volable) {};
// Ennemi::~Ennemi(){};

// to be overriten
void Ennemi::attaquer(Personnage* hero){}
void Ennemi::afficher() {}
void Ennemi::special(Personnage* hero) {}

void Ennemi::afficherStats(){
    std::cout << std::endl << std::endl;
    std::cout << "\t+------ "<< race <<" -----+" << std::endl << std::endl;
    std::cout << "\t\tHP: " << vie << "/" << vieMax<< std::endl;
    std::cout << "\t\tForce: " << force << std::endl;
    std::cout << "\t\trecompense: " << recompenseOr << Icone::GOLD;
    std::cout << std::endl << std::endl;
    std::cout << "\t+-------------------+" << std::endl << std::endl;

}

void Ennemi::recevoirDegats(int degat) {
    if (degat < vie)
        vie -= degat;
    else 
        vie = 0;
}

bool Ennemi::estVivant(){
    if (vie > 0)
        return true;
    else
        return false;
}

std::string Ennemi::getRace() { return race; }
int Ennemi::getVie() { return vie; }
int Ennemi::getVieMax() { return vieMax; }
int Ennemi::getForce() { return force; }
int Ennemi::getRecompenseOr() { return recompenseOr; }
bool Ennemi::estVolable() { return volable; } 

void Ennemi::setVolable(bool vole) { volable = vole; }
