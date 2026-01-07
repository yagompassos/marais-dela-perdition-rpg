#ifndef ENNEMI_H
#define ENNEMI_H

#include <string>

// forward declaration to avoid including problems
class Personnage;

class Ennemi {
protected:
    std::string race;
    int vieMax;
    int vie;
    int force;
    int recompenseOr;
    bool volable;
public:
    Ennemi();
    Ennemi(std::string race, int vieMax, int force, int recompenseOr, bool volable);
    virtual ~Ennemi() = default;

    // getters
    std::string getRace();
    int getVieMax();
    int getVie();
    int getForce();
    int getRecompenseOr();

    // methods
    virtual void attaquer(Personnage* hero);
    void recevoirDegats(int degat);
    bool estVivant();
    bool estVolable();
};

#endif