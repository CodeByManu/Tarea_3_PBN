#include <string>
#include <iostream>

#include "mapa.h"

Mapa::Mapa() {}

Mapa::Mapa(int ancho, int alto) {
    this -> ancho = ancho;
    this -> alto = alto;
}

void Mapa::crearMapa(int ancho, int alto) {    
    tablero = new std::string*[ancho];
    for (int i = 0; i < ancho; i++) {
        tablero[i] = new std::string[alto*2];
    }

    for (int y = 0; y < alto*2; y++) {
        for (int x = 0; x < ancho; x++){
            if (y%2 == 0) tablero[x][y] = "     ";
            else tablero [x][y] = "_____";
        }
    }
}

void Mapa::agregarPersonaje(Personaje *personaje) {
    Posicion pos = personaje -> getPos();
    int espacios = 5 - personaje -> getNombre().length();

    tablero[pos.getX()][pos.getY()*2] = personaje -> getNombre() + std::string(espacios, ' ');
    tablero[pos.getX()][pos.getY()*2 + 1] = "__" + personaje -> ejercito + "__";
}

void Mapa::eliminarPersonaje(Personaje* personaje) {
    std::cout << personaje -> getNombre() << " ha sido eliminado (" << personaje -> getPos().getX() << ", " << personaje -> getPos().getY() << ")" << std::endl;
    tablero[personaje -> getPos().getX()][personaje -> getPos().getY()*2] = "     ";
    tablero[personaje -> getPos().getX()][personaje -> getPos().getY()*2 + 1] = "_____";
}

int Mapa::getAncho() {
    return ancho;
}

int Mapa::getAlto() {
    return alto;
}

void Mapa::setCentro(Posicion centro) {
    this -> centro = centro;
}

Posicion Mapa::getCentro() {
    return centro;
}

Mapa::~Mapa(){
    for (int i = 0; i < ancho; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
}