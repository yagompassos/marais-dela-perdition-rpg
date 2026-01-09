#include "Entities/Personnage.hpp"
#include "Entities/Ennemi.hpp"
#include "Items/Objet.hpp" 
#include <iostream>

Personnage::Personnage(){};                                                                                                                                // Here we create a 4 size pointer vector with all null pointers
Personnage::Personnage(int vm, int forc, int dex, int cha, int gld, int szInv) : vieMax(vm), vie(vm), force(forc), dexterite(dex), chance(cha), gold(gld), inventaire(szInv, nullptr) {}
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

void Personnage::curer(int v) {
    if (vie + v < vieMax)
        vie += v;
    else
        vie = vieMax;
}

void Personnage::enricher(int goldGagne) {
    gold += goldGagne;
}

void Personnage::afficherInventaire(){
    std::cout<< "| ";
    for (int i=0; i<inventaire.size(); i++){
        if (inventaire[i]==nullptr)
            std::cout << "   | ";
        else 
            std::cout << inventaire[i]->getNom() << " |";
    }
    std::cout << std::endl;
}

bool Personnage::ajouterObjet(Objet* obj) {
    int i=0;
    while (inventaire[i] != nullptr) {
        i++;
        if (i>=inventaire.size()) {
            std::cout << "inventaire rempli." << std::endl;
            return false;
        }
    }
    inventaire[i] = obj;
    return true;
}

bool Personnage::utiliserObjet(int index){
    std::cout << inventaire.size() << std::endl;
    if (index >= inventaire.size())
        return false;
    inventaire[index]->utiliser(this);
    inventaire[index] = nullptr;
    return true;
}