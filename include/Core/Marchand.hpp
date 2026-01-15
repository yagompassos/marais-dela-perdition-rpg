#ifndef MARCHAND_H
#define MARCHAND_H

class Personnage;

// Si le marchand a le prix des objets et si c'est lui qui decide les prix, il faut enlever le prix sur les sous-classes des objets
class Marchand {
    private:
        int prixPotion = 2;
    public:
    int getPrixPotion();
        Marchand();
        virtual ~Marchand();
        bool vendrePotion(Personnage* hero);
        /*
        preferer de faire un

        Objet* vendre(TypeObjet type, Personnage& hero);

        au lieu d'un fonction pour chaque vende.
        */

        bool vendre(int op, Personnage* hero);

        void afficher();
};

#endif