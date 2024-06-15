#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Referee.h"

class Juego {
private:
public:
    void colocarNaves(Jugador& jugador, int naves);
    void iniciar(int size, int naves);
};

#endif // JUEGO_H
