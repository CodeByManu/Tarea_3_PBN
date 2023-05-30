#ifndef MAPA_H
#define MAPA_H

#include "personaje.h"

class Personaje;

class Mapa {
    private:
        int ancho;
        int alto;
        Posicion centro;
    public:
        std::string **tablero;
        Mapa();
        Mapa(int, int);
        void crearMapa(int, int);
        void agregarPersonaje(Personaje*);
        void eliminarPersonaje(int, int);
        int getAncho();
        int getAlto();
        void setCentro(Posicion);
        Posicion getCentro();
        ~Mapa();
};

#endif