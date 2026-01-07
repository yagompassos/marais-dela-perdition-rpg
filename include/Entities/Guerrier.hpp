#ifndef GUERRIER_H
#define GUERRIER_H

#include "Entities/Personnage.hpp"

class Ennemi;

class Guerrier : public Personnage {
public:
    Guerrier();
    void attaqueBasique(Ennemi* e) override;
    void coupePuissant();
};

#endif