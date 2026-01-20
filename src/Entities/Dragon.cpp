#include "Entities/Dragon.hpp"
#include "Entities/Personnage.hpp"
#include "Core/icones.hpp"
#include "Core/Des.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void animationDes();

                            //race    vm frc gld volable
Dragon::Dragon() : Ennemi("DRAGON", 100, 50, 1000, false) {}

void Dragon::attaquer(Personnage* hero){
    std::cout << "Le dragon vous attaque avec s aile!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    hero->recevoirDegats(force);
}

void Dragon::afficher() {
    std::cout << Icone::DRAGON;
}

void Dragon::special(Personnage* hero) {
    int d20 = Des::D20();
    std::cout << d20 ;

    std::cout << "Le dragon va réaliser un attaque special!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    animationDes();
    std::cout << d20 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    
    if (d20 == 1) {
        std::cout << std::endl<< "FAIL!, le dragon est un bebe" << std::endl;
        return;
    }

    if (d20 >=19) {
        std::cout<< "Crache du feu. C'est un attaque Critique! Dégats(x1.8) = " << force*1.8 << std::endl;
        int vm = hero->getVieMax();
        hero->recevoirDegats(force*2);
        hero->setVieMax(vm-10);
        std::cout << "Vous avez perdu 10 points de vie max." << std::endl;
    } else if (d20 >=10 ){
        std::cout<< "Crache du feu! Dégats = " << force*1.4 << std::endl;
        hero->recevoirDegats(force*1.4);
    } else {
        std::cout<< "Pas trop feu! Dégats(x0.7) = " << force << std::endl;
        hero->recevoirDegats(force);
    }
}

void animationDes() {
    std::cout << "Lancement des dés";
    std::cout.flush();

    for (int i = 0; i < 3; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << ".";
        std::cout.flush();
    }

    std::cout << " ";
}