#include "personaje.h"

class Juego{
    private:
        // atributos (?)
    public:
        Juego();
        void jugar();
        void chequearGanador();
        int calcularTurno();
        void mostrarMapa();
        void combate(Personaje*, Personaje*);
};