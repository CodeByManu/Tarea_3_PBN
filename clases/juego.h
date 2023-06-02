#include "mapa.h"
#include "ejercito.h"

class Juego{
    private:
        int estado;
        Mapa *tablero;
        int ancho;
        int alto;
        int indice = 0;
        int turno = 0;
        void combateDes(Personaje*, Personaje*);
        void combateDef(Personaje*, Personaje*);
    public:
        // Atributos publicos
        Ejercito ejercito1;
        Ejercito ejercito2;
        Posicion movimiento;
        Posicion rastro;
        int ejercitoActual = 0;
        int ejercitoEnemigo = 1;
        // Metodos
        Juego();
        void jugar();
        int chequearGanador();
        int calcularTurno();
        void turnoDes(Ejercito, Ejercito);
        int quienParte();
        void mostrarMapa();
        void combate(Personaje*, Personaje*);
        Personaje* llamarEnemigo(Posicion, Ejercito);
        int loopDelJuego(); // Idea
        // Getters
        int getEstado();
        // Setters
        void setMapa(Mapa*);
};