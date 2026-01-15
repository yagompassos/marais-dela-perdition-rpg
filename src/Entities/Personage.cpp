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

bool Personnage::appauvrir(int prix) {
    if (prix > gold){
        std::cout << "Pas assez d'argent" << std::endl;
        return false;
    } 
    gold -= prix;
    return true;
}

void Personnage::afficherInventaire(){
    std::cout << std::endl;
    std::cout << "======INVENTAIRE======" << std::endl;
    std::cout << std::endl;
    std::cout << "    1   2   3   4 " << std::endl;
    std::cout<< "  | ";
    for (int i=0; i<inventaire.size(); i++){
        if (inventaire[i]==nullptr)
        std::cout << " ";
        else 
        inventaire[i]->afficher();
        std::cout << " | ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "======================" << std::endl;
}

void Personnage::afficherStats() {
    std::cout << std::endl << std::endl;
    std::cout << "------------------------------------------------ hero stats ------------------------------------------------" << std::endl << std::endl;
    std::cout << "\tHP: " << vie << "/" << vieMax;
    std::cout << "\t\tGold: " << gold;
    std::cout << std::endl << std::endl;
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
    if (index >= inventaire.size())
        return false;
    if (inventaire[index]==nullptr)
        return false;
    inventaire[index]->utiliser(this);
    inventaire[index] = nullptr;
    return true;
}