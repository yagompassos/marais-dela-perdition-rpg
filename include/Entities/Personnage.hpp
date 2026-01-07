#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <vector>

class Ennemi;

// Abstract
class Personnage {
protected:
    // std::string nom;
    int vieMax;
    int vie;
    int force;
    int dexterite;
    int chance;
    int gold;
    // std::vector<Objet*> inventaire;

public:
    Personnage();
    Personnage(int vm, int forc, int dex, int cha, int gld);
    virtual ~Personnage() = default;

    // getters
    std::vector<int> getAttributes();
    int getVieMax();
    int getVie();
    int getForce();
    int getDexterite();
    int getChance();
    int getGold();

    // methods
    virtual void attaqueBasique(Ennemi* e);
    void recevoirDegats(int degat);
    void utiliserObjet(int index);
    void ajouterGold(int goldGagne);

};

#endif