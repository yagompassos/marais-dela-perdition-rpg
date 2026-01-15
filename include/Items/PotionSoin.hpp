#ifndef POTIONSOIN_H
#define POTIONSOIN_H

#include "Items/Objet.hpp"

class Personnage;

class PotionSoin : public Objet {
private:
    int pointsVie;
public:
    PotionSoin();

    void utiliser(Personnage* hero) override;
    void afficher() override;
};

#endif