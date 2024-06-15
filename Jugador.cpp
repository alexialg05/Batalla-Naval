#include "Jugador.h"
#include <iostream> // Necesario para std::cout y std::endl

Jugador::Jugador(std::string nombre, int size) : nombre(nombre), tablero(size) {}

std::string Jugador::getNombre() {
    return nombre;
}

Tablero& Jugador::getTablero() {
    return tablero;
}

bool Jugador::realizarAtaque(Jugador& oponente, int x, int y) {
    if (oponente.getTablero().recibirAtaque(x, y)) {
        tablero.actualizarTablero(x-1, y-1, 'X');
        std::cout << "Ataque acertado!" << std::endl;
        if(oponente.getTablero().naveHundida(x, y)) {
            std::cout << "Nave hundida!" << std::endl;
        }
        return true;
    } else {
        tablero.actualizarTablero(x-1, y-1, 'O');
        std::cout << "Ataque fallido!" << std::endl;
        return false;
    }
}
void Jugador::mostrarTablero() {
    tablero.mostrar();
}
void Jugador::colocarNave(int longitud, bool orientacion, int x, int y) {
    tablero.nuevaNave(Nave(longitud, orientacion, x, y));
}