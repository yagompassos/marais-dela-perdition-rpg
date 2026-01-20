#ifndef VOLEUR_H
#define VOLEUR_H

#include "Entities/Personnage.hpp"

class Ennemi;

class Voleur : public Personnage {
public:
    Voleur();
    Voleur(std::string nom);
    void attaqueBasique(Ennemi* e) override;
    void habiliteSpeciale(Ennemi *e) override;
    std::string getEmoji() const override;
    void afficherStats() override;
    void afficherActionsCombat() override;

};

#endif