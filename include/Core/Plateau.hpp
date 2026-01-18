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

    int getLargeur();
    int getHauteur();

    void afficher(int xJoueur, int yJoueur);
    bool dedantLimits(int x, int y); 
    Case& getCase(int x, int y);
    void retirerObjetDeCase(int x, int y);
};


#endif