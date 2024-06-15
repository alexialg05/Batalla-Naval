#include "Tablero.h"
#include <iostream> // Necesario para std::cout y std::endl

Tablero::Tablero(int size) : tablero(size, std::vector<char>(size, '~')) {}

// Private
bool Tablero::ataqueAcertado(int x, int y) {
    for (auto& nave : naves) {
        for (auto& pos : nave.getPosiciones()) {
            if (pos[0] == x && pos[1] == y) {
                nave.impactar();
                return true;
            }
        }
    }
    return false;
}
// Public
int Tablero::getSize() const {
    return tablero.size();
}

void Tablero::nuevaNave(Nave nave) {
    naves.push_back(nave);
}

bool Tablero::todasNavesHundidas() {
    for (auto& nave : naves) {
        if (!nave.isHundido()) {
            return false;
        }
    }
    return true;
}

void Tablero::mostrar() {
    std::cout << "     ";
    for (int i = 0; i < tablero.size(); i++) {
        std::cout << i+1 << "   ";
    }
    std::cout << std::endl;
    std::cout << "   ----------------------------------------" << std::endl;
    for (int i = 0; i < tablero.size(); i++) {
        if(i < 9) {
            std::cout << " " << i+1 << " | ";
        } else {
            std::cout << i+1 << " | ";
        }
        for (int j = 0; j < tablero[i].size(); j++) {
            std::cout << tablero[i][j] << " | ";
        }
        std::cout << std::endl;
        std::cout << "   ----------------------------------------" << std::endl;
    }
}

bool Tablero::recibirAtaque(int x, int y) {
    if (ataqueAcertado(x, y)) {
        return true;
    } else {
        return false;
    }
}

void Tablero::actualizarTablero(int x, int y, char impacto) {
    tablero[x][y] = impacto;
}
bool Tablero::naveHundida(int x, int y) {
    for (auto& nave : naves) {
        for (auto& pos : nave.getPosiciones()) {
            if (pos[0] == x && pos[1] == y) {
                return nave.isHundido();
            }
        }
    }
    return false;
}
bool Tablero::verificarPosicion(int x, int y, int longitud, bool orientacion) {
    // Verificar que la nave no se sobreponga con otra
    for (auto& nave : naves) {
        for (auto& pos : nave.getPosiciones()) {
            if (orientacion) {
                for (int i = 0; i < longitud; i++) {
                    if (pos[0] == x + i && pos[1] == y) {
                        return false;
                    }
                }
            } else {
                for (int i = 0; i < longitud; i++) {
                    if (pos[0] == x && pos[1] == y + i) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool Tablero::posicionAtaqueValida(int x, int y) {
    if(x >= 0 && x < tablero.size() && y >= 0 && y < tablero.size()) {
        return tablero[x][y] == '~';
    }
    return false;
}