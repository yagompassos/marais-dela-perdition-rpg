#ifndef GOBELIN_H
#define GOBELIN_H

#include <string>
#include "Entities/Ennemi.hpp"

class Personnage;

class Gobelin : public Ennemi {
public:
    Gobelin();
    
    void attaquer(Personnage* hero) override;
    void afficher() override;
};

#endif