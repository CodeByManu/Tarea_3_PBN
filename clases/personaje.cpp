#include "personaje.h"

Personaje::Personaje():pos{pos} {}

Personaje::Personaje(std::string nombre, int vida, int daño, int velocidad, Posicion pos):pos{pos}
{ //Debido a que pos no tiene constructor predeterminado (lo hicimos nosotros)
    this -> nombre = nombre;
    this -> vida = vida;
    this -> daño = daño;
    this -> velocidad = velocidad;
}

int Personaje::ataque() {
    return daño;
}

void Personaje::recibirAtaque(Personaje *enemigo) {
    vida -= enemigo -> daño;
}

Posicion Personaje::moverse() {
    int x = pos.getX();
    int y = pos.getY();
    // if ((x && y) != )
}

std::string Personaje::getNombre() {
    return nombre;
}

int Personaje::getVida() {
    return vida;
}

int Personaje::getDaño() {
    return daño;
}

int Personaje::getVelocidad() {
    return velocidad;
}

Posicion Personaje::getPos() {
    return pos;
}