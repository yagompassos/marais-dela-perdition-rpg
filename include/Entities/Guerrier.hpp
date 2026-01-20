#ifndef GUERRIER_H
#define GUERRIER_H

#include "Entities/Personnage.hpp"

class Ennemi;

class Guerrier : public Personnage {
public:
    Guerrier();
    Guerrier(std::string nom);
    void attaqueBasique(Ennemi* e) override;
    void habiliteSpeciale(Ennemi *e) override;
    std::string getEmoji() const override;
    void afficherStats() override;
    void afficherActionsCombat() override;

};

#endif