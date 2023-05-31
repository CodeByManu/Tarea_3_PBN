#include "mapa.h"
#include "ejercito.h"

class Juego{
    private:
        Mapa *tablero;
        int ancho;
        int alto;
        void combateDes(Personaje*, Personaje*);
        void combateDef(Personaje*, Personaje*);
    public:
        // Atributos publicos
        Ejercito ejercito1;
        Ejercito ejercito2;
        // Metodos
        Juego();
        void jugar();
        int chequearGanador(Personaje**, int, Personaje**, int);
        int calcularTurno();
        int quienParte();
        void mostrarMapa();
        void combate(Personaje*, Personaje*);
        Personaje* llamarEnemigo(Posicion, Ejercito);
        // Setters
        void setMapa(Mapa*);
};