#include <iostream>
#include <string>
#include <vector>
#include "Core/Jeu.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

void configurerTerminal() {
    #ifdef _WIN32
    SetConsoleOutputCP(65001); // accepts UTF-8
    #endif
}

int main() {
    configurerTerminal();

    Jeu jeu(8, 8);

    jeu.lancer();
    
    return 0;
}