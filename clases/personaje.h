#pragma once

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
        // Atributos publicos
        Posicion posPrevia;
        std::string ejercito; //Publico o privado?
        std::string estado = "vivo";
        int combatePendiente = 0;
        // Metodos
        Personaje();
        Personaje(std::string, int, int, int, Posicion);
        int ataque();
        void recibirAtaque(Personaje*);
        Posicion moverse();
        void matar(Personaje*);
        std::string getNombre();
        // Getters
        int getVida();
        int getDanio();
        int getVelocidad();
        Posicion getPos();
        // Setters
        void setPos(int, int);
        void setMapa(Mapa*);
        // Destructor
        ~Personaje();
};