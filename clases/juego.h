#include "mapa.h"

class Juego{
    private:
        Mapa *tablero;
        int ancho;
        int alto;
        void combateDes(Personaje*, Personaje*);
        void combateDef(Personaje*, Personaje*);
    public:
        Personaje **ejercito1;
        int n1;
        Personaje **ejercito2;
        int n2;
        Juego();
        void jugar();
        int chequearGanador(Personaje**, int, Personaje**, int);
        int calcularTurno();
        int quienParte();
        void mostrarMapa();
        void combate(Personaje*, Personaje*);
        void setMapa(Mapa*); // Se puede?
        Personaje* llamarEnemigo(Posicion, Personaje**, int n);
};