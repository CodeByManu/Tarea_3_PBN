#include "personaje.h"

class Juego{
    Juego::Juego();

    void jugar();

    void chequearGanador();

    int calcularTurno();

    void mostrarMapa();

    void combate(Personaje*, Personaje*);
};