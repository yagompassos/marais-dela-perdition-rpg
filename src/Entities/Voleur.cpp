#include "Entities/Voleur.hpp"
#include "Entities/Ennemi.hpp"
#include "Core/Des.hpp"
#include "Items/PotionSoin.hpp"
#include "Core/icones.hpp"

//                            vm frc pwr, dex cha gld sizeInventory
Voleur::Voleur() : Personnage(70, 18, 3, 75, 100, 10, 5) {}
Voleur::Voleur(std::string nom) : Personnage(nom, 70, 18, 3, 75, 100, 10, 5) {}

std::string Voleur::getEmoji() const { return Icone::VOLEUR; }


void Voleur::attaqueBasique(Ennemi* e) {
    int d20 = Des::D20();
    std::cout << d20 ;
    
    if (d20 == 1) {
        std::cout << std::endl<< "FAIL!, vous ne serts pas a rien." << std::endl;
        return;
    }

    int chanceTotal = d20+(d20*chance/100);
    
    std::cout << " + chance ("<< chance <<"%) = " << chanceTotal << std::endl;
    
    if (chanceTotal >=19) {
        std::cout<< "Attaque furtive! Dégats(x1.8) = " << force*1.8 << std::endl;
        e->recevoirDegats(force*1.8);
    } else if (chanceTotal >=10 ){
        std::cout<< "Attaque! Dégats = " << force << std::endl;
        e->recevoirDegats(force);
    } else {
        std::cout<< "Attaque faible! Dégats(x0.7) = " << force*0.7 << std::endl;
        e->recevoirDegats(force*0.7);
    }
}

void Voleur::habiliteSpeciale(Ennemi *e) {
    int d20 = Des::D20();
    std::cout << d20 ;

    if (d20 == 1) {
        std::cout << std::endl<< "FAIL!, vous ne serts pas a rien." << std::endl;
        return;
    }

    int chanceTotal = d20+(d20*chance/100);
    
    std::cout << " + chance ("<< chance <<"%) = " << chanceTotal << std::endl;
    
    if (chanceTotal >=19) {
        std::cout<< "T'as volé le mf " << std::endl;
        PotionSoin *p = new PotionSoin;
        this->enricher(5);
        this->ajouterObjet(p);
        e->setVolable(false);
    } else if (chanceTotal >=10 ){
        std::cout<< "bien volé! "  << std::endl;
        PotionSoin *p = new PotionSoin;
        this->ajouterObjet(p);
        e->setVolable(false);
    } else {
        std::cout<< "c'est quoi que tu fait la? Pas reussi en voler" << std::endl;
        // rien
    }
}

void Voleur::afficherStats() {
    std::cout << std::endl << std::endl;
    std::cout << "------------------------------------------------ "<< getNom() <<" le Vouleur. ------------------------------------------------" << std::endl << std::endl;
    std::cout << "\tHP: " << vie << "/" << vieMax;
    std::cout << "\tForce: " << force;
    std::cout << "\tDexterite: " << dexterite;
    std::cout << "\tChance:" << chance;
    std::cout << "\tGold: " << gold << Icone::COIN;
    std::cout << std::endl << std::endl;
}

void Voleur::afficherActionsCombat(){
    std::cout << "================================================== ACTIONS ==================================================" << std::endl << std::endl;
    std::cout << "\t1. Attaque \t 2. Volert \t 3. Inventaire \t 4. Fuir " << std::endl << std::endl;
    std::cout << "=============================================================================================================" << std::endl;
    std::cout << "\t\tOption: " ;
}