#include "Core/Marchand.hpp"
#include "Entities/Personnage.hpp"
#include "Items/PotionSoin.hpp"
#include "Core/icones.hpp"
#include <iostream>
#include <string>

Marchand::Marchand(){}
Marchand::~Marchand(){}

int Marchand::getPrixPotion(){
    return prixPotion;
};

bool Marchand::vendre(int op, Personnage* hero) {
    Objet *p = nullptr;
    int prix = 0;

    switch(op) {
        case 1:
            p = new PotionSoin();
            prix = prixPotion;
            break;
    }

    if ( !hero->appauvrir(prix) ) 
        return false;
    if ( !hero->ajouterObjet(p) ) {
        hero->enricher(prix);
        return false;
    }
    return true;
}

void Marchand::afficher() {
        std::cout << std::endl;
    std::cout << "\t\t\t\t=======================" << std::endl;
    std::cout << "\t\t\t\tBienvenue au Marchand!" << std::endl;
    std::cout << std::endl;
    std::cout << "\t\t\t\t\tmenu du jour:" << std::endl;
    std::cout << "\t\t\t\t  Potion de Soin " << Icone::COIN << " " << prixPotion << std::endl;
    std::cout << "\t\t\t\t  Bouclier " << Icone::COIN << std::endl;
    std::cout << "\t\t\t\t  Epee long " << Icone::COIN << std::endl;
    std::cout << "\t\t\t\t  Parchemin " << Icone::COIN << std::endl;
    std::cout << std::endl ;
    std::cout << "\t\t\t\tpassez votre commande!" << std::endl;
    std::cout << "\t\t\t\t=======================" << std::endl;
    std::cout << std::endl << std::endl;
}
 
    
// deprecated
bool Marchand::vendrePotion(Personnage* hero){
    PotionSoin *p = new PotionSoin();
    if ( !hero->appauvrir(p->getPrix()) )
        return false;
    if ( !hero->ajouterObjet(p) ) {
        hero->enricher(p->getPrix());
        return false;
    }
    return true;
}