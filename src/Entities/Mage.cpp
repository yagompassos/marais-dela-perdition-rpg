#include "Entities/Mage.hpp"
#include "Entities/Ennemi.hpp"
#include "Core/Des.hpp"
#include "Core/icones.hpp"

//                        vm frc pwr, dex cha gld sizeInventory
Mage::Mage() : Personnage(60, 10, 20, 25, 35, 5, 4) {}
Mage::Mage(std::string nom) : Personnage(nom, 60, 10, 20, 25, 35, 5, 4) {}

std::string Mage::getEmoji() const { return Icone::MAGE; }


void Mage::attaqueBasique(Ennemi* e) {
    int d20 = Des::D20();
    std::cout << d20 ;
    
    if (d20 == 1) {
        std::cout << std::endl<< "FAIL!, vous vous avez oublié comment faire le sort d'attaque." << std::endl;
        return;
    }

    int chanceTotal = d20+(d20*chance/100);
    
    std::cout << " + chance ("<< chance <<"%) = " << chanceTotal << std::endl;
    
    if (chanceTotal >=19) {
        std::cout<< "Sort Critique! Dégats(x1.8) = " << pouvoir*1.8 << " et tu te cures un petit peu." << std::endl;
        e->recevoirDegats(pouvoir*1.8);
        this->curer(7);
    } else if (chanceTotal >=10 ){
        std::cout<< "Sort! Dégats = " << pouvoir << std::endl;
        e->recevoirDegats(pouvoir);
    } else {
        std::cout<< "Sort faible! Dégats(x0.7) = " << pouvoir*0.7 << std::endl;
        e->recevoirDegats(pouvoir*0.7);
    }
}

void Mage::habiliteSpeciale(Ennemi *e) {
    int d20 = Des::D20();
    std::cout << d20 ;

    if (d20 == 1) {
        std::cout << std::endl<< "FAIL!, vous vous avez oublié comment faire le sort de cure" << std::endl;
        return;
    }

    int chanceTotal = d20+(d20*chance/100);
    
    std::cout << " + chance ("<< chance <<"%) = " << chanceTotal << std::endl;
    
    if (chanceTotal >=19) {
        std::cout<< "Votre chant ressone fort (x1.8). Tu te cures et l'ennemi reçoit un dégats." << std::endl;
        this->curer(pouvoir);
    } else if (chanceTotal >=10 ){
        std::cout<< "Cure! " << pouvoir/2 << " points de vie." << std::endl;
        this->curer(pouvoir/2);
    } else {
        std::cout<< "voice crack, vos sorts sont pas si forts. -4 points de vie." << std::endl;
        this->recevoirDegats(4);
    }
}

void Mage::afficherStats() {
    std::cout << std::endl << std::endl;
    std::cout << "------------------------------------------------ "<< getNom() <<" le Mage. ------------------------------------------------" << std::endl << std::endl;
    std::cout << "\tHP: " << vie << "/" << vieMax;
    std::cout << "\tPouvoir: " << pouvoir;
    std::cout << "\tChance:" << chance;
    std::cout << "\tGold: " << gold << Icone::COIN;
    std::cout << std::endl << std::endl;
}

void Mage::afficherActionsCombat(){
    std::cout << "================================================== ACTIONS ==================================================" << std::endl << std::endl;
    std::cout << "\t1. Attaque \t 2. Cure \t 3. Inventaire \t 4. Fuir " << std::endl << std::endl;
    std::cout << "=============================================================================================================" << std::endl;
    std::cout << "\t\tOption: " ;
}