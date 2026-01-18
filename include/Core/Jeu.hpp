#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "Core/Plateau.hpp"
#include "Core/Marchand.hpp"
#include "Core/EtatJeu.hpp"

class Personnage;
class Ennemi;

class Jeu {
private: 
    Personnage *joueur;
    Plateau plateau;
    Marchand marchand;
    EtatJeu etatJeu;
    int xJoueur;
    int yJoueur;
public:
    Jeu();
    Jeu(int largeur, int hauteur);
    virtual ~Jeu();
    void setJoueur(Personnage* p);
    bool deplacerJoueur(int dx, int dy);
    void afficherPlateau();
    void lancer();
    void bouclePreJeu();
    void boucleExploration();
    void boucleCombat();
    void GameOver();
    void afficherOptionsPreJeu() ;
    void afficherOptionsExploration();
    void animationDes();
    void afficherActionsMarchand();
    void afficherActionsCombat();
    void afficherTitre();
    int getXJoueur();
    int getYJoueur();
    bool estCaseVisible(int x, int y) const;
    void rondJoueur(Ennemi *ennemi);
    void rondEnnemi(Ennemi *ennemi);
};

#endif