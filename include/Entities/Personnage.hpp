#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <vector>

class Ennemi;
class Objet;

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
    std::vector<Objet*> inventaire;

public:
    Personnage();
    Personnage(int vm, int forc, int dex, int cha, int gld, int szInv);
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
    bool ajouterObjet(Objet* obj);
    void curer(int v);
    void enricher(int g);
    bool appauvrir(int prix);
    void afficherInventaire();
    void afficherStats();
    bool utiliserObjet(int index);
};

#endif