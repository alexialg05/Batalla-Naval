#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Tablero.h"

class Jugador {
private:
    std::string nombre;
    Tablero tablero;
    


public:
    Jugador(std::string nombre, int size);
    std::string getNombre();
    Tablero& getTablero();
    bool realizarAtaque(Jugador& oponente, int x, int y);
    void mostrarTablero();
    void colocarNave(int longitud, bool orientacion, int x, int y);
};

#endif // JUGADOR_H
