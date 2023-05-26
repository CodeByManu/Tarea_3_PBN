#include "personaje.h"

Personaje::Personaje():pos{pos} {}

Personaje::Personaje(std::string nombre, int vida, int danio, int velocidad, Posicion pos):pos{pos}
{ //Debido a que pos no tiene constructor predeterminado (lo hicimos nosotros)
    this -> nombre = nombre;
    this -> vida = vida;
    this -> danio = danio;
    this -> velocidad = velocidad;
}

int Personaje::ataque() {
    return danio;
}

void Personaje::recibirAtaque(Personaje *enemigo) {
    vida -= enemigo -> danio;
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

int Personaje::getDanio() {
    return danio;
}

int Personaje::getVelocidad() {
    return velocidad;
}

Posicion Personaje::getPos() {
    return pos;
}