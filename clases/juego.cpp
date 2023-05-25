#include <iostream>

#include "juego.h"

Juego::Juego():tablero{tablero} {}

void Juego::jugar() {
    // TODO
}

void Juego::chequearGanador() {
    // TODO
}

int Juego::calcularTurno() {
    // TODO
}

void Juego::mostrarMapa() {
    for (int i = 0; i < ancho; i++) std::cout << " _____";
    std::cout << std::endl;
    for(int i = 0; i < alto*2; i++){
        std::cout << '|';
        for(int j = 0; j < ancho; j++) std::cout << tablero.tablero[j][i] << '|';
        std::cout << std::endl;
    }
}

void Juego::combate(Personaje *p1, Personaje *p2) {
    // TODO
}

void Juego::setMapa(Mapa *tablero) {
    this -> tablero = *tablero;
    ancho = tablero -> getAncho();
    alto = tablero -> getAlto();
}