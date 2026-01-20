#include "Entities/Guerrier.hpp"
#include "Entities/Ennemi.hpp"
#include "Core/Des.hpp"
#include "Core/icones.hpp"

//                               vm frc pwr dex cha gld sizeInventory
Guerrier::Guerrier() : Personnage(80, 20, 7, 8, 30, 3, 4) {}
Guerrier::Guerrier(std::string nom) : Personnage(nom, 80, 20, 7, 8, 30, 3, 4) {}

std::string Guerrier::getEmoji() const {return Icone::GUERRIER; }

void Guerrier::attaqueBasique(Ennemi* e) {
    int d20 = Des::D20();
    std::cout << d20 ;
    
    if (d20 == 1) {
        std::cout << std::endl<< "FAIL!, vous vous avez trébuché et raté l'attaque" << std::endl;
        return;
    }

    int chanceTotal = d20+(d20*chance/100);
    
    std::cout << " + chance ("<< chance <<"%) = " << chanceTotal << std::endl;
    
    if (chanceTotal >=19){
        std::cout<< "Attaque Critique! Dégats(x1.8) = " << force*1.8 << std::endl;
        e->recevoirDegats(force*1.8);
    } else if (chanceTotal >=10 ){
        std::cout<< "Attaque! Dégats = " << force << std::endl;
        e->recevoirDegats(force);
    } else {
        std::cout<< "Attaque faible! Dégats(x0.7) = " << force*0.7 << std::endl;
        e->recevoirDegats(force*0.7);
    }
}

void Guerrier::habiliteSpeciale(Ennemi *e) {
    int d20 = Des::D20();
    std::cout << d20 ;
    
    if (d20 == 1) {
        std::cout << std::endl<< "FAIL!, vous vous avez trébuché et raté l'attaque" << std::endl;
        return;
    }

    int chanceTotal = d20+(d20*chance/100);
    
    std::cout << " + chance ("<< chance <<"%) = " << chanceTotal << std::endl;
    
    if (chanceTotal >=19){
        std::cout<< "Saut avec l attaque! Dégats(x1.8) = " << force*2 << std::endl;
        e->recevoirDegats(force*1.8);
    } else if (chanceTotal >=10 ){
        std::cout<< "Attaque! Dégats = " << force*1.2 << std::endl;
        e->recevoirDegats(force*1.2);
    } else {
        std::cout<< "Attaque faible! Dégats(x0.7) = " << force*0.7 << std::endl;
        e->recevoirDegats(force*0.7);
    }
}

void Guerrier::afficherStats() {
    std::cout << std::endl << std::endl;
    std::cout << "------------------------------------------------ "<< getNom() <<" le Guerrier. ------------------------------------------------" << std::endl << std::endl;
    std::cout << "\tHP: " << vie << "/" << vieMax;
    std::cout << "\tForce: " << force;
    std::cout << "\tChance:" << chance;
    std::cout << "\tGold: " << gold << Icone::COIN;
    std::cout << std::endl << std::endl;
}

void Guerrier::afficherActionsCombat(){
    std::cout << "================================================== ACTIONS ==================================================" << std::endl << std::endl;
    std::cout << "\t1. Attaque \t 2. Attaque Special \t 3. Inventaire \t 4. Fuir " << std::endl << std::endl;
    std::cout << "=============================================================================================================" << std::endl;
    std::cout << "\t\tOption: " ;
}