#include "Core/Jeu.hpp"
#include "Entities/Guerrier.hpp"
#include "Entities/Gobelin.hpp"
#include "Core/Des.hpp"
#include "Core/Case.hpp"
#include "Core/icones.hpp"
#include <stdio.h>
#include <thread>
#include <chrono>


Jeu::Jeu(int largeur, int hauteur) : joueur(nullptr), plateau(largeur, hauteur), marchand(), etatJeu(), xJoueur(0), yJoueur(0) {}

Jeu::~Jeu() {}

void Jeu::afficherPlateau(){
    for (int y = plateau.getHauteur() - 1; y >= 0; y--) {
        std::cout << "\t";
        for (int x = 0; x < plateau.getLargeur(); x++) {
            if (x==xJoueur && y==yJoueur)
                std::cout << Icone::JOUEUR;
            else {
                bool visible = estCaseVisible(x, y);
                plateau.getCase(x, y).afficher(visible);
            }
            std::cout << "   ";

        }
        std::cout << std::endl;
    }
}


void Jeu::setJoueur(Personnage *p) {
    joueur = p;
}

bool Jeu::deplacerJoueur(int dx, int dy) {
    if (!plateau.dedantLimits(dx, dy))
        return false;
    
    xJoueur = dx;
    yJoueur = dy;
    return true;
}

void Jeu::lancer(){
    do{
        switch(etatJeu){
            case EtatJeu::PreJeu:
                bouclePreJeu();
                break;
            case EtatJeu::Exploration:
                boucleExploration();
                break;
            case EtatJeu::Combat:
                break;
            case EtatJeu::GameOver:
                break;
            
        }
    } while(etatJeu != EtatJeu::Quitter);

    if (etatJeu == EtatJeu::Quitter) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Merci pour Jouer!" << std::endl;
    }        
}

void Jeu::bouclePreJeu() {
    int op;
    Personnage *hero = nullptr;
    
    afficherOptionsPreJeu();
    std::cin >> op;
    switch (op) {
        case 1:
            std::cout << "Guerrier!" << std::endl;
            hero = new Guerrier();
            break;
    }
    joueur = hero ;
    etatJeu = EtatJeu::Exploration;
}

void Jeu::boucleExploration() {
    int op, subOp, tirage;
    char moveCmd;

    afficherTitre();
    joueur->afficherStats();
    afficherPlateau();
    std::cout << std::endl;
    afficherOptionsExploration();

    std::cin >> op;
    switch (op){
        case 1:
            afficherTitre();
            joueur->afficherStats();
            afficherPlateau();
            std::cout << std::endl;
            std::cout << "Appuyer ENTER pour Lancer le Des 4" << std::endl;
            std::cin.ignore();
            getchar();

            afficherTitre();
            joueur->afficherStats();
            afficherPlateau();
            std::cout << std::endl;
            animationDes();
            tirage = Des::D4();
            std::cout << tirage << std::endl;
            while (tirage>0)
            {
                afficherTitre();
                joueur->afficherStats();
                afficherPlateau();
                std::cout << std::endl;
                std::cout << "Appuyez sur WASD pour bouger." << std::endl;
                std::cout << "Vous avez " << tirage << " mouvements." << std::endl;
                std::cin >> moveCmd;
                switch (moveCmd) 
                {
                case 'w':
                    if(deplacerJoueur(xJoueur, yJoueur+1 ))
                        tirage--;
                    break;
                case 'd':
                    if(deplacerJoueur(xJoueur+1, yJoueur))
                        tirage--;
                    break;
                case 's':
                    if (deplacerJoueur(xJoueur, yJoueur-1))
                    tirage--;
                    break;
                case 'a':
                    if (deplacerJoueur(xJoueur-1, yJoueur))
                    tirage--;
                    break;
                }
            }
            break;
        case 2:
            // AFFICHER INVENTAIRE
            do {
                std::cout << "\033[2J\033[1;1H";
                joueur->afficherStats();
                joueur->afficherInventaire();
                
                std::cout << "0. Revenir" << std::endl;
                std::cin >> subOp;
                if (subOp >= 1 && subOp <=4)
                    joueur->utiliserObjet(subOp-1);
            } while(subOp != 0);
            break;
        case 3:
            // OUVRIR MARCHAND
            joueur->enricher(10);
            joueur->recevoirDegats(15);
            do {
                std::cout << "\033[2J\033[1;1H";
                joueur->afficherStats();
                marchand.afficher();
                std::cin >> subOp;
                if (subOp>=1 && subOp<=5)
                    marchand.vendre(subOp, joueur);
            } while (subOp != 0);
            break;
        case 4:
            etatJeu = EtatJeu::Quitter;
            break;
        default:
            break;
    }
}

void Jeu::afficherOptionsPreJeu() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Marais de Perdition" << std::endl;
    std::cout << "Jouer comme:" << std::endl;
    std::cout << "1. Guerrier" << std::endl;
    std::cout << "2. Mage" << std::endl;
    std::cout << "3. Voleur" << std::endl;
}

void Jeu::afficherOptionsExploration() {
    std::cout << "================================================ ACTIONS ================================================" << std::endl << std::endl;
    std::cout << "\t1. Bouger \t 2. Inventaire \t\t 3. Marchand \t\t 4. Quitter Jeu" << std::endl << std::endl;
    std::cout << "=========================================================================================================" << std::endl;
    std::cout << "\t\tOption: " ;
}

void Jeu::afficherActionsMarchand(){
    std::cout << "================================================ ACTIONS ================================================" << std::endl << std::endl;
    std::cout << "\t1. acheter Potion \t 2. acheter Bouclier \t 3. acheter Epee \t 4. acheter Parchemin \t 5. Revenir" << std::endl << std::endl;
    std::cout << "=========================================================================================================" << std::endl;
    std::cout << "\t\tOption: " ;
}

void Jeu::animationDes() {
    std::cout << "Lancement des dés";
    std::cout.flush();

    for (int i = 0; i < 3; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << ".";
        std::cout.flush();
    }

    std::cout << " ";
}

void Jeu::afficherTitre() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "=========================================== MARAIS DE LA PERDITION ===========================================" << std::endl << std::endl;
}

bool Jeu::estCaseVisible(int x, int y) const {
    int dx = std::abs(x - xJoueur);
    int dy = std::abs(y - yJoueur);

    return dx <= 1 && dy <= 1;
}

int Jeu::getXJoueur(){ return xJoueur; }
int Jeu::getYJoueur(){ return yJoueur; }
