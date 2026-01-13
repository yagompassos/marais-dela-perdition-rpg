#include "Core/Random.hpp"
#include <random>
#include <stdexcept>
#include <algorithm>

namespace {
    std::mt19937& generateur() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return gen;
    }
}

int Random::entier(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    return dist(generateur());
}

std::vector<int> Random::entiersDistincts(int min, int max, int quantite) {
    int taille = max - min + 1;
    if (quantite > taille) {
        throw std::invalid_argument("Quantité trop grande pour la plage donnée");
    }

    std::vector<int> valeurs;
    for (int i = min; i <= max; ++i) {
        valeurs.push_back(i);
    }

    std::shuffle(valeurs.begin(), valeurs.end(), generateur());

    valeurs.resize(quantite);
    return valeurs;
}
