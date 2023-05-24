#include <string>
#include "mapa.h"

Mapa::Mapa(int ancho, int alto) {
    this -> ancho = ancho;
    this -> alto = alto;
}
// Diferencia entre constructor y crearMapa??
void Mapa::crearMapa(int ancho, int alto) {
// _____ -> Jose_ (nombre)
// _____ -> __1__ (# ejercito)
    
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

void Mapa::agregarPersonaje(Personaje personaje) {
    Posicion pos = personaje.getPos();
    int espacios = 5 - personaje.getNombre().length();

    tablero[pos.getX() - 1][pos.getY()*2] = personaje.getNombre() + std::string(espacios, ' ');
}

void Mapa::eliminarPersonaje(Personaje *personaje) {}

Mapa::~Mapa(){
    for (int i = 0; i < ancho; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
}