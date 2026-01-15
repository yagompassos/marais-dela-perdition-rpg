#include "Items/Objet.hpp"
#include "Entities/Personnage.hpp"

Objet::Objet(std::string nom, int prix) : nom(nom), prix(prix) {}

std::string Objet::getNom() { return nom; }
int Objet::getPrix() { return prix; }

// to override:
void Objet::utiliser(Personnage* hero){}
void Objet::afficher(){}
