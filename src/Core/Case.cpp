#include "Core/Case.hpp"
#include "Entities/Ennemi.hpp"
#include "Items/Objet.hpp"
#include <iostream>

Case::Case() : goldTrouve(0), objet(nullptr), ennemi(nullptr), visite(false) {}
Case::Case(int goldTrouve) : goldTrouve(goldTrouve), objet(nullptr), ennemi(nullptr), visite(false) {}
Case::Case(Objet* obj) : goldTrouve(0), objet(obj), ennemi(nullptr), visite(false){}
Case::Case(Ennemi* enn) : goldTrouve(0), objet(nullptr), ennemi(enn), visite(false){}
Case::~Case(){}

bool Case::estVisite() { return visite; }
void Case::marquerVisite() { visite = true; }

void Case::retirerEnnemi() { ennemi = nullptr; }
void Case::retirerItem() { objet = nullptr; }

bool Case::estVide(){
    if (objet == nullptr && ennemi == nullptr){
        std::cout << "l'Case est vide" << std::endl; 
        return true;
    } 
    return false;
}

bool Case::contientEnnemi(){
    if (ennemi == nullptr)
        return false;
    else 
        return true;
}

bool Case::contientObjet(){
    if (objet == nullptr)
        return false;
    else 
        return true;
}

void Case::afficher() {
    if (contientEnnemi())
        std::cout << "E" ; // changer pour      ennemi->afficher();
    else if (contientObjet())
        std::cout << "O" ;
    else if (goldTrouve > 0)
        std::cout << goldTrouve;
    else
        std::cout << "_" ;
}
