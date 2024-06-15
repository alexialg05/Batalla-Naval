#include "Nave.h"
#include <iostream> 

Nave::Nave(int longitud, bool orientacion, int x, int y)
    : longitud(longitud), hits(0), orientacion(orientacion), x(x), y(y) {
    generarPosiciones();
    }

int Nave::getLongitud() {
    return longitud;
}

bool Nave::isHundido() {
    return hits >= longitud;
}

bool Nave::getOrientacion() {
    return orientacion;
}

int Nave::getX() {
    return x;
}

int Nave::getY() {
    return y;
}

void Nave::impactar() {
    hits++;
}
std::vector<std::vector<int>> Nave::getPosiciones() {
    return posiciones;
}

void Nave::generarPosiciones() {
    std::cout << "Generando posiciones de la nave" << std::endl;
    std::cout << "Longitud: " << longitud << std::endl;
    std::cout << "Orientacion: " << orientacion << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
    for (int i = 0; i < longitud; i++) {
        std::vector<int> pos;
        pos.push_back(orientacion ? x : x + i);
        pos.push_back(orientacion ? y + i : y);
        std::cout << "Posicion: x: " << pos[0] << " y: " << pos[1] << std::endl;
        posiciones.push_back(pos);
    }
}