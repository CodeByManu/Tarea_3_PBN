#include "personaje.h"

class Mapa {
    private:
        int ancho;
        int alto;
    public:
        Mapa::Mapa(int, int);
        void crearMapa(int, int);
        void agregarPersonaje(Personaje*);
        void eliminarPersonaje(Personaje*);
};