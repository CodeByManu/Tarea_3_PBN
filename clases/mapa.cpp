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
    // typedef struct personaje {
    //     std::string nombre;
    //     int ejercito;
    // }personaje;

    // personaje tablero[ancho][alto][2];
    std::string x[alto*2][ancho][5];
    // tablero = x;
    
    // for (size_t y = 0; y < alto*2; y++){
    //     for (size_t x = 0; x < ancho; x++){
    //         if ()
    //     }
    // }
}

void Mapa::agregarPersonaje(Personaje *personaje) {}

void Mapa::eliminarPersonaje(Personaje *personaje) {}