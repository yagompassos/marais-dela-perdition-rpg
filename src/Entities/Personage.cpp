#include "Entities/Personnage.hpp"
#include "Entities/Ennemi.hpp"
#include "Items/Objet.hpp" 
#include "Core/Des.hpp"

Personnage::Personnage(){};                                                                                                                                // Here we create a 4 size pointer vector with all null pointers
Personnage::Personnage(int vm, int forc, int dex, int cha, int gld, int szInv) : vieMax(vm), vie(vm), force(forc), dexterite(dex), chance(cha), gold(gld), inventaire(szInv, nullptr) {}
// Personnage::~Personnage(){};

int Personnage::getVieMax() { return vieMax; }
int Personnage::getVie() { return vie; }
int Personnage::getGold() { return gold; }


// to override
void Personnage::attaqueBasique(Ennemi* e){}

bool Personnage::fuir() {
    int d20 = Des::D20();
std::cout << d20 ;
    
    if (d20 == 1) {
        std::cout << std::endl<< "FAIL!, vous vous avez raté la fuite" << std::endl;
        return false;
    }

    int chanceTotal = d20+(d20*chance/100);
    
    std::cout << " + chance ("<< chance <<"%) = " << chanceTotal << std::endl;
    
    if (chanceTotal >=20){
        std::cout<< "Fuite parfait, t'as disparu et l'ennemi pense avoir mangé quelque champignon gâté." << std::endl;
        return true;
    } else if (chanceTotal >=15 ){
        std::cout<< "Fuite, l'ennemi the cherce encore mais t'as bien fuit." << std::endl;
        return true;
    } 
    std::cout<< "Tu ne vas nulle part. " << std::endl;
    return false;
}

void Personnage::recevoirDegats(int degat) {
    if (degat < vie)
        vie -= degat;
    else {
        vie = 0;
        std::cout << "GAME OVER" << std::endl << "You died." << std::endl;
    }
}

void Personnage::curer(int v) {
    if (vie + v < vieMax)
        vie += v;
    else
        vie = vieMax;
}

void Personnage::enricher(int goldGagne) {
    gold += goldGagne;
}

bool Personnage::appauvrir(int prix) {
    if (prix > gold){
        std::cout << "Pas assez d'argent" << std::endl;
        return false;
    } 
    gold -= prix;
    return true;
}

void Personnage::afficherInventaire(){
    std::cout << std::endl;
    std::cout << "======INVENTAIRE======" << std::endl;
    std::cout << std::endl;
    std::cout << "    1   2   3   4 " << std::endl;
    std::cout<< "  | ";
    for (int i=0; i<inventaire.size(); i++){
        if (inventaire[i]==nullptr)
        std::cout << " ";
        else 
        inventaire[i]->afficher();
        std::cout << " | ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "======================" << std::endl;
}

void Personnage::afficherStats() {
    std::cout << std::endl << std::endl;
    std::cout << "------------------------------------------------ hero stats ------------------------------------------------" << std::endl << std::endl;
    std::cout << "\tHP: " << vie << "/" << vieMax;
    std::cout << "\t\tGold: " << gold;
    std::cout << std::endl << std::endl;
}

bool Personnage::estInventaireComplet() {
    for (auto obj : inventaire){
        if (obj == nullptr)
            return false;
    }
    return true;
}

bool Personnage::ajouterObjet(Objet* obj) {
    int i = 0;
    if (estInventaireComplet()) {
        i = remplacerObjetSurInventaire(obj);
        if (i==0)
            return false;
    }
    else {
        while (inventaire[i] != nullptr) {
            i++;
            if (i>=inventaire.size()) {
                remplacerObjetSurInventaire(obj);
            }
        }
    }
    inventaire[i] = obj;
    return true;
}

int Personnage::remplacerObjetSurInventaire(Objet* obj) {
    int i;
    afficherInventaire();
    std::cout << "Inventaire complet! choisir une option à remplacer" << std::endl;
    std::cout << "================================================== ACTIONS ==================================================" << std::endl << std::endl;
    for (i=0; i<inventaire.size(); i++)
        std::cout << "\t" << i+1 << ". Remplacer "<< inventaire[i]->getNom();
    std::cout << "\t0. Jeter nouveau objet." << std::endl << std::endl;
    std::cout << "=============================================================================================================" << std::endl;
    std::cout << "\t\tOption: " ; 
    std::cin >> i;
    return i;
}

bool Personnage::utiliserObjet(int index){
    if (index >= inventaire.size())
        return false;
    if (inventaire[index]==nullptr)
        return false;
    inventaire[index]->utiliser(this);
    inventaire[index] = nullptr;
    return true;
}