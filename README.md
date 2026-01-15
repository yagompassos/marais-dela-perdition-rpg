# Marais de la Perdition
**OORPG !**

C'est à dire:  **O**bject **O**riented **R**ole **P**lay **G**ame!

## How to Run

### Dependences
- MinGW g++ compiler
- CMake 

### Compilation sur Linux
```bash
mkdir build
cd build
cmake ..
make
./rpg
```

### Compilation sur Windows
```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
rpg.exe
```

### Relancer la compilation
Si j'amais vous avez besoin de tout refaire à niveau build, lancez ce command sur la racine du projet pour bien effacer:
```bash
Remove-Item -Recurse -Force build
```

## Tests
 
Pour lancer un test, si vous avez dejá fait la build, il sufit de lancer le fichier de test de son choix:
```bash
cd build
./test_entities
```

## Developpement:

Le developpement du jeu suit ce chronogramme:
1. 06/01 - Modelisation UML 
2. 08/01 - Implementation de classes
3. 10/01 - Toutes fonctionalités marchant
4. 15/01 - Jeu simple sur terminal
5. 20/01 - Toutes classes imlpementés
5. 25/01 - Ajout de et pdcurses e ncurses pour meilleur visualizer le jeu
6. ?     - Refactoraction avec exceptions.
7. ?     - Developper tableau (BFS/DFS pour trouver les cases possibles à aller)