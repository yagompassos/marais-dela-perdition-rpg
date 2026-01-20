#ifndef MAGE_H
#define MAGE_H

#include "Entities/Personnage.hpp"

class Ennemi;

class Mage : public Personnage {
public:
    Mage();
    Mage(std::string nom);
    void attaqueBasique(Ennemi* e) override;
    void habiliteSpeciale(Ennemi *e) override;
    std::string getEmoji() const override;
    void afficherStats() override;
    void afficherActionsCombat() override;
};

#endif