#include "personaje.h"

class Mapa {
    Mapa::Mapa(int, int);

    void crearMapa(int, int);

    void agregarPersonaje(Personaje*);

    void eliminarPersonaje(Personaje*);
};