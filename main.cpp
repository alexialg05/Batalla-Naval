#include <iostream>
#include "./Nave.h"
#include "./Tablero.h"
#include "./Jugador.h"
#include "./Referee.h"
#include "./Juego.h"

int main() {
    int size = 10;
    int naves = 6;
    Juego juego;
    std::cout << "Ingrese el la dimension del tablero: ";
    std::cin >> size;
    std::cout << "Ingrese la cantidad de naves: ";
    std::cin >> naves;
    juego.iniciar(size, naves);
    return 0;
}