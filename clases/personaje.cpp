#include "personaje.h"

Personaje::Personaje(std::string nombre, int vida, int daño, int velocidad, Posicion pos):pos{pos} { //Debido a que pos no tiene constructor predeterminado (lo hicimos nosotros)
    this -> nombre = nombre;
    this -> vida = vida;
    this -> daño = daño;
    this -> velocidad = velocidad;
}

int Personaje::ataque() {}

void Personaje::recibirAtaque(Personaje *enemigo) {}

void Personaje::moverse() {}