#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <vector>

class Random {
public:
    static int entier(int min, int max);

    static std::vector<int> entiersDistincts(int min, int max, int quantite);
};

#endif
