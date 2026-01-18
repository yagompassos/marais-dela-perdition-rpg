#include "Core/Jeu.hpp"
#include "Entities/Guerrier.hpp"
#include "Entities/Gobelin.hpp"
#include "Core/Des.hpp"
#include "Core/Case.hpp"
#include "Core/icones.hpp"
#include "Items/Objet.hpp"
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
                boucleCombat();
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
    Case caseActuel;

    afficherTitre();
    joueur->afficherStats();
    afficherPlateau();
    std::cout << std::endl;
    afficherOptionsExploration();

    std::cin >> op;
    switch (op){
        // OPTION 1. BOUGER 
        case 1:
            afficherTitre();
            joueur->afficherStats();
            afficherPlateau();
            std::cout << std::endl;
            std::cout << "Appuyer ENTER pour Lancer le Des 4" << std::endl;
            std::cin.ignore();
            getchar();
            // lancement de dés
            afficherTitre();
            joueur->afficherStats();
            afficherPlateau();
            std::cout << std::endl;
            animationDes();
            tirage = Des::D4();
            std::cout << tirage << std::endl;
            // mouvementation
            while (tirage>0)
            {
                afficherTitre();
                joueur->afficherStats();
                afficherPlateau();
                std::cout << std::endl;
                std::cout << "Appuyez sur WASD pour bouger." << std::endl;
                std::cout << "Vous avez " << tirage << " mouvements." << std::endl;
                std::cin >> moveCmd;
                switch (moveCmd) {
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
            // Verifie si la case arrivé a quelque chose
            caseActuel = plateau.getCase(xJoueur, yJoueur);
            if (caseActuel.contientEnnemi()) {
                afficherTitre();
                std::cout << std::endl<< std::endl<< std::endl << "DANGER! " << caseActuel.getEnnemi()->getRace() << "!" << std::endl;
                std::cout << "Appuyez sur ENTER pour entrer en combat." << std::endl;
                std::cin.ignore();
                getchar();
                etatJeu = EtatJeu::Combat;
            } else if (caseActuel.contientObjet()) {
                Objet *obj= caseActuel.getObjet();
                afficherTitre();
                std::cout << std::endl<< std::endl<< std::endl << "Vous avez trouvez un "  << obj->getNom() << "!" << std::endl;
                std::cout << "Appuyez sur ENTER pour ajouter au inventaire." << std::endl;
                std::cin.ignore();
                getchar();
                if ( joueur->ajouterObjet(obj) ) 
                    plateau.getCase(xJoueur, yJoueur).retirerItem();
            }
            break;

            // OPTION 2. AFFICHER INVENTAIRE
        case 2: 
            do {
                afficherTitre();
                joueur->afficherStats();
                joueur->afficherInventaire();
                
                std::cout << "0. Revenir" << std::endl;
                std::cin >> subOp;
                if (subOp >= 1 && subOp <=4)
                    joueur->utiliserObjet(subOp-1);
            } while(subOp != 0);
            break;
            // OPTION 3. OUVRIR MARCHAND
        case 3:
            do {
                afficherTitre();
                joueur->afficherStats();
                marchand.afficher();
                afficherActionsMarchand();
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

void Jeu::boucleCombat(){
    Ennemi *ennemi = plateau.getCase(xJoueur, yJoueur).getEnnemi();
    int op, tirage, recompense;

    do {
        rondJoueur(ennemi);

        if ( !ennemi->estVivant() ){
            recompense = ennemi->getRecompenseOr();
            etatJeu = EtatJeu::Exploration;
            joueur->enricher(recompense);
            plateau.getCase(xJoueur, yJoueur).retirerEnnemi();
            std::cout << std::endl;
            std::cout << "\tYou killed them all!" << std::endl;
            std::cout << "\t+" << recompense << Icone::GOLD << std::endl;
            std::cout << std::endl;
            std::cout << "\tAppuyer ENTER pour continuer!" << std::endl;
            std::cin.ignore();
            getchar();
        } else 
            rondEnnemi(ennemi);
        
        if ( !joueur->estVivant() ) {
            etatJeu = EtatJeu::GameOver;
            
        }
    } while(etatJeu == EtatJeu::Combat);
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
    std::cout << "================================================== ACTIONS ==================================================" << std::endl << std::endl;
    std::cout << "\t1. Bouger \t 2. Inventaire \t\t 3. Marchand \t\t 4. Quitter Jeu" << std::endl << std::endl;
    std::cout << "=============================================================================================================" << std::endl;
    std::cout << "\t\tOption: " ;
}

void Jeu::afficherActionsMarchand(){
    std::cout << "================================================== ACTIONS ==================================================" << std::endl << std::endl;
    std::cout << "\t1. acheter Potion \t 2. acheter Bouclier \t 3. acheter Epee \t 4. acheter Parchemin \t 0. Revenir" << std::endl << std::endl;
    std::cout << "=============================================================================================================" << std::endl;
    std::cout << "\t\tOption: " ;
}

void Jeu::afficherActionsCombat(){
    std::cout << "================================================== ACTIONS ==================================================" << std::endl << std::endl;
    std::cout << "\t1. Attaque basique \t 2. Attaque Fort \t 3. Inventaire \t 4. Fuir " << std::endl << std::endl;
    std::cout << "=============================================================================================================" << std::endl;
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
    std::cout << "============================================= MARAIS DE LA PERDITION =============================================" << std::endl << std::endl;
}


bool Jeu::estCaseVisible(int x, int y) const {
    int dx = std::abs(x - xJoueur);
    int dy = std::abs(y - yJoueur);

    return dx <= 1 && dy <= 1;
}

int Jeu::getXJoueur(){ return xJoueur; }
int Jeu::getYJoueur(){ return yJoueur; }

void Jeu::rondJoueur(Ennemi *ennemi) {
    int op;

    afficherTitre();
    ennemi->afficherStats();
    joueur->afficherStats();
    afficherActionsCombat();
    std::cin >> op;

    switch (op) {
        case 1:
            afficherTitre();
            ennemi->afficherStats();
            joueur->afficherStats();
            std::cout << "\tAttaque Basique!"<< std::endl;
            std::cout << "\tAppuyer ENTER pour Lancer le Des 20" << std::endl;
            std::cin.ignore();
            getchar();
            //affichage des
            afficherTitre();
            ennemi->afficherStats();
            joueur->afficherStats();
            std::cout << std::endl;
            animationDes();
            joueur->attaqueBasique(ennemi);
            std::cout << std::endl << "\t ENTER pour continuer" << std::endl;
            std::cin.ignore();
            getchar();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            afficherTitre();
            ennemi->afficherStats();
            joueur->afficherStats();
            std::cout << "\tTu essaie de Fuir!" << std::endl;
            std::cout << "\tAppuyer ENTER pour Lancer le Des 20" << std::endl;
            std::cin.ignore();
            getchar();
            // affichage des
            afficherTitre();
            ennemi->afficherStats();
            joueur->afficherStats();
            std::cout << std::endl;
            animationDes();
            if ( joueur->fuir() ) {
                etatJeu = EtatJeu::Exploration;
                std::cout << "\tAppuyer ENTER pour continuer" << std::endl;
                std::cin.ignore();
                getchar();
            }
            break;
        }
}

void Jeu::rondEnnemi(Ennemi *ennemi) {
    afficherTitre();
    ennemi->afficherStats();
    joueur->afficherStats();
    std::cout << std::endl;
    std::cout << ennemi->getRace() << "t'a attaque" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ennemi->attaquer(joueur);
    std::cout << "Damage";
    std::cout << "\tAppuyer ENTER pour continuer" << std::endl;
    std::cin.ignore();
    getchar();
}
