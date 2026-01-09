#include "Core/Marchand.hpp"
#include "Entities/Personnage.hpp"
#include "Items/PotionSoin.hpp"
#include <iostream>
#include <string>

Marchand::Marchand(){}
Marchand::~Marchand(){}

int Marchand::getPrixPotion(){
    return prixPotion;
};

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
 