#include "Referee.h"

bool Referee::verificarGanador(Jugador& jugador) {
    return jugador.getTablero().todasNavesHundidas();
}
