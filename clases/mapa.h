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
        // Atributos publicos
        std::string **tablero;
        // Metodos
        Mapa();
        Mapa(int, int);
        void crearMapa(int, int);
        void agregarPersonaje(Personaje*);
        void eliminarPersonaje(Personaje*);
        // Getters
        int getAncho();
        int getAlto();
        // Setters
        void setCentro(Posicion);
        Posicion getCentro();
        // Destructor
        ~Mapa();
};

#endif