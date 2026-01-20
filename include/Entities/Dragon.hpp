#ifndef DRAGON_H
#define DRAGON_H

#include <string>
#include "Entities/Ennemi.hpp"

class Personnage;

class Dragon : public Ennemi {
public:
    Dragon();
    
    void attaquer(Personnage* hero) override;
    void afficher() override;
    void special(Personnage* hero);
};

#endif