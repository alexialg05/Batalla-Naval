#include "Juego.h"
#include <iostream> // Necesario para std::cout y std::endl

void Juego::colocarNaves(Jugador& jugador, int naves) {
    int x, y, longitud, orientacionInt;
    bool orientacion;

    std::cout << jugador.getNombre() << "======== Coloca tus barcos =========" << std::endl;
    for (int i = 0; i < naves; i++) {
        bool valid = false;
        while(!valid) {
            std::cout << "Barco " << i+1 << " de " << naves << std::endl;
            std::cout << "Tipo de barco: Barco (1), Acorazado (2), Portaaviones (3): ";
            std::cin >> longitud;
            if (!(longitud >= 1 && longitud <= 3)) {
                std::cout << "Tipo de barco invalido, intenta de nuevo" << std::endl;
                continue;
            }
            std::cout << "Orientacion (0 - Vertical, 1 - Horizontal): ";
            std::cin >> orientacionInt;
            if(orientacionInt == 0) {
                orientacion = false;
            } else if(orientacionInt == 1) {
                orientacion = true;
            } else {
                std::cout << "Orientacion invalida, intenta de nuevo" << std::endl;
                continue;
            }
            std::cout << "Coordenadas (x y): ";
            std::cin >> x >> y;
            if(orientacion) {
                if(x + longitud - 1 > jugador.getTablero().getSize()) {
                    std::cout << "Posicion invalida, intenta de nuevo" << std::endl;
                    continue;
                }
            } else {
                if(y + longitud - 1 > jugador.getTablero().getSize()) {
                    std::cout << "Posicion invalida, intenta de nuevo" << std::endl;
                    continue;
                }
            } 
            if(jugador.getTablero().verificarPosicion(x, y, longitud, orientacion)) {
                jugador.colocarNave(longitud, orientacion, x, y);
                valid = true;
            } else {
                std::cout << "Posicion invalida, intenta de nuevo" << std::endl;
            }
        }
    }
}

void Juego::iniciar(int size, int naves) {
    Jugador jugador1("Jugador 1", size);
    Jugador jugador2("Jugador 2", size);
    Referee referee;

    // Colocar naves en el tablero
    colocarNaves(jugador1, naves);
    colocarNaves(jugador2, naves);

    bool juegoEnCurso = true;
    while (juegoEnCurso) {
        int x, y;

        std::cout << "==== Turno de " << jugador1.getNombre() << " ====" << std::endl;
        std::cout << jugador1.getNombre() << " - Tablero del oponente:" << std::endl;
        jugador1.getTablero().mostrar();

        do {
            std::cout << jugador1.getNombre() << ", ingresa las coordenadas de ataque (x y): ";
            std::cin >> x >> y;
        } while (!jugador1.getTablero().posicionAtaqueValida(x-1, y-1));

        jugador1.realizarAtaque(jugador2, x, y);

        if (referee.verificarGanador(jugador2)) {
            std::cout << jugador1.getNombre() << " ha ganado!" << std::endl;
            break;
        }

        std::cout << "==== Turno de " << jugador2.getNombre() << " ====" << std::endl;
        std::cout << jugador2.getNombre() << " - Tablero del oponente:" << std::endl;
        jugador2.getTablero().mostrar();

        do {
            std::cout << jugador2.getNombre() << ", ingresa las coordenadas de ataque (x y): ";
            std::cin >> x >> y;
        } while (!jugador2.getTablero().posicionAtaqueValida(x-1, y-1));

        jugador2.realizarAtaque(jugador1, x, y);

        if (referee.verificarGanador(jugador1)) {
            std::cout << jugador2.getNombre() << " ha ganado!" << std::endl;
            break;
        }
    }
}
