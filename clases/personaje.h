#include <string>

#include "posicion.h"

class Personaje{
    private:
        std::string nombre;
        int vida;
        int daño;
        int velocidad;
        Posicion pos;
    public:
        Personaje();
        Personaje(std::string, int, int, int, Posicion);
        int ataque();
        void recibirAtaque(Personaje*);
        Posicion moverse();
        std::string getNombre();
        int getVida();
        int getDaño();
        int getVelocidad();
        Posicion getPos();
};