#ifndef NAVE_H
#define NAVE_H

#include <vector>
#include "./Nave.h"

class Nave {
private:
    int longitud;
    std::vector<std::vector<int>> posiciones;
    int hits;
    bool orientacion; // true for horizontal, false for vertical
    int x, y;
    void generarPosiciones();
public:
    Nave(int longitud, bool orientacion, int x, int y);
    int getLongitud();
    bool isHundido();
    bool getOrientacion();
    int getX();
    int getY();
    void impactar();
    std::vector<std::vector<int>> getPosiciones();
};

#endif // NAVE_H
