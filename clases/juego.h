#include "mapa.h"

class Juego{
    private:
        Mapa tablero;
        int ancho;
        int alto;
    public:
        Juego();
        void jugar();
        void chequearGanador();
        int calcularTurno();
        void mostrarMapa();
        void combate(Personaje*, Personaje*);
        void setMapa(Mapa*); // Se puede?
};