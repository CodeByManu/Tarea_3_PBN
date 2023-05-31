#include "ejercito.h"

Ejercito::Ejercito() {}

Ejercito::Ejercito(Personaje **ejercito) {
    this -> personajes = ejercito;
}

void Ejercito::setCantidad(int cantidad) {
    this -> cantidad = cantidad;
}

int Ejercito::getVelMedia() {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) suma += personajes[i] -> getVelocidad();
    velocidadMedia = suma/cantidad;
    return velocidadMedia;
}

int Ejercito::getCantidad() {
    return cantidad;
}