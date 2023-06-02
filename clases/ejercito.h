#pragma once

#include "personaje.h"

class Ejercito {
    private:
        int cantidad;
        int velocidadMedia;
    public:
        // Atributos Publicos
        Personaje **personajes;
        // Metodos
        Ejercito();
        Ejercito(Personaje**);
        // Setters
        void setCantidad(int);
        // Getters
        int getCantidad();
        int getVelMedia();
};