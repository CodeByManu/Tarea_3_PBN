#include "mapa.h"

class Juego{
    private:
        Mapa *tablero;
        Personaje **equipo1;
        Personaje **equipo2;
        int ancho;
        int alto;
        void combateDes(Personaje*, Personaje*);
    public:
        Juego();
        void jugar();
        int chequearGanador(Personaje**, int, Personaje**, int);
        int calcularTurno();
        int quienParte(Personaje**, int, Personaje**, int);
        void mostrarMapa();
        void combate(Personaje*, Personaje*);
        void setMapa(Mapa*); // Se puede?
        Personaje* llamarEnemigo(Posicion, Personaje**, int n);
};