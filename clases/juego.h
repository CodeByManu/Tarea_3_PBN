#include "personaje.h"

class Juego{
    void jugar();

    void chequearGanador();

    int calcularTurno();

    void mostrarMapa();

    void combate(Personaje, Personaje);
};