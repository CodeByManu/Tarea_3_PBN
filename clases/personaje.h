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
        void moverse(); //Que tipo tiene que ser? (void para que funcionara nomas)
        Posicion getPos();
        std::string getNombre();
};