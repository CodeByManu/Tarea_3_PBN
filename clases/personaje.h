#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

#include "posicion.h"
#include "mapa.h"

class Mapa;

class Personaje{
    private:
        std::string nombre;
        int vida;
        int danio;
        int velocidad;
        Mapa *tablero;
        Posicion pos;
    public:
        Posicion posPrevia;
        std::string ejercito; //Publico o privado?
        std::string estado = "vivo";
        int combatePendiente = 0;
        Personaje();
        Personaje(std::string, int, int, int, Posicion);
        int ataque();
        void recibirAtaque(Personaje*);
        Posicion moverse();
        void matar(Personaje*);
        std::string getNombre();
        int getVida();
        int getDanio();
        int getVelocidad();
        Posicion getPos();
        void setPos(Posicion);
        void setMapa(Mapa*);
        ~Personaje();
};

#endif