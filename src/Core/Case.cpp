#include "Core/Case.hpp"
#include "Entities/Ennemi.hpp"
#include "Items/Objet.hpp"
#include "Core/icones.hpp"
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
    if (objet == nullptr && ennemi == nullptr)
        return true;
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

void Case::afficher(bool visible) {
    if (!visible)
        std::cout << Icone::VIDE ;
    else if (contientEnnemi())
        ennemi->afficher();
    else if (contientObjet() || goldTrouve > 0)
        std::cout << Icone::BAU ;
    else
        std::cout << Icone::ILE ;
}
