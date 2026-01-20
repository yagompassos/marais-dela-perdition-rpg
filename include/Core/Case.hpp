// SONT LES CASES DU JEU

#ifndef CASE_H
#define CASE_H

class Objet;
class Ennemi;

class Case {
private:
    int goldTrouve;
    Objet* objet;
    Ennemi* ennemi;
    bool visite;
public: 
    Case();
    Case(int goldTrouve);
    Case(Objet* obj);
    Case(Ennemi* enn);
    virtual ~Case();

    //getters
    Ennemi* getEnnemi();
    Objet* getObjet();
    int getGoldTrouve();

    void setGoldtrouve(int gld);

    bool estVide();
    bool estVisite();
    void marquerVisite();
    bool contientEnnemi();
    bool contientObjet();
    void retirerEnnemi();
    void retirerItem(); 
    void afficher(bool visible);
};

#endif