#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Nave.h"

class Tablero {
private:
    std::vector<std::vector<char>> tablero;
    std::vector<Nave> naves;
    bool ataqueAcertado(int x, int y);
public:
    Tablero(int size);
    void nuevaNave(Nave nave);
    bool recibirAtaque(int x, int y);
    bool naveHundida(int x, int y);
    bool todasNavesHundidas();
    void mostrar();
    void actualizarTablero(int x, int y, char impacto);
    int getSize() const;
    bool verificarPosicion(int x, int y, int longitud, bool orientacion);
    bool posicionAtaqueValida(int x, int y);
};

#endif // TABLERO_H
