#ifndef MARCHAND_H
#define MARCHAND_H

class Personnage;
class PotionSoin;
class Bouclier;
class Epee;
class Parchemin;

class Marchand {
    private:
        int prixPotion = 2;
    public:
    int getPrixPotion();
        Marchand();
        virtual ~Marchand();
        bool vendrePotion(Personnage* hero);
        Bouclier vendreBouclier(Personnage* hero);
        Epee vendreEpee(Personnage* hero);
        Parchemin vendreParchemin(Personnage* hero);
};

#endif