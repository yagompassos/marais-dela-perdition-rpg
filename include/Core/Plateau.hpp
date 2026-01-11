// C'EST LE PLATEAU DU JEU

#ifndef PLATEAU_H
#define PLATEAU_H

#include <vector>

class Case;

class Plateau {
private: 
    int largeur;
    int hauteur;
    std::vector<std::vector<Case>> grille;

public:
    Plateau(int largeur, int hauteur);
    virtual ~Plateau();

    void afficher();
    void remplirAleatoirement(int quantiteEnnemi, int quantiteObjets); 
    // bool deplacerJoueur(int x, int y);  CEST LEL JEU QUI LE DEPLACE 
    Case& getCase(int x, int y);
};


#endif