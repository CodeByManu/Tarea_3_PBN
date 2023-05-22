#include "personaje.h"

class Mapa {
    private:
        std::string ***tablero;
        int ancho;
        int alto;
    public:
        Mapa(int, int);
        void crearMapa(int, int);
        void agregarPersonaje(Personaje*);
        void eliminarPersonaje(Personaje*);
};