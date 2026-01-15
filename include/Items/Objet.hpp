#ifndef OBJET_H
#define OBJET_H

#include <string>

class Personnage;

class Objet {
protected:
    std::string nom;
    // L'objet n'as pas un prix! Qui define ça c'est le marchand
    int prix;
public:
    Objet(std::string nom, int prix);
    virtual ~Objet() = default;

    // getters
    std::string getNom();
    int getPrix();

    // methods
    virtual void utiliser(Personnage* hero);
    virtual void afficher();
};

#endif