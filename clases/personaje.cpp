#include "personaje.h"
#include "juego.h"
#include <iostream>

Personaje::Personaje():pos{pos} {}

Personaje::Personaje(std::string nombre, int vida, int danio, int velocidad, Posicion pos) {
    this -> nombre = nombre;
    this -> vida = vida;
    this -> danio = danio;
    this -> velocidad = velocidad;
    this -> pos = pos;
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

    int xAux = x;
    int yAux = y;

    int xCentro = tablero -> getCentro().getX();
    int yCentro = tablero -> getCentro().getY();

    //x, y != centro <--------------------------------

    if (x > xCentro) x--;
    else if (x < xCentro) x++;
    if (y*2 > yCentro) y--;
    else if (y*2 < yCentro) y++;

    if (tablero -> tablero[x][y*2] == "     ") {
        pos = Posicion (x, y);
        tablero -> eliminarPersonaje(xAux, yAux);
        tablero -> agregarPersonaje(this);
        return pos;
    } else {
        x = xAux;
        y = yAux;
        // if (tablero -> tablero[x][y*2 + 1][2] != this -> ejercito)
    }

    // if ((x != xCentro) && (y*2 != yCentro)) {
    //     if (x > xCentro) {
    //         if (y*2 < yCentro) {
    //             if (tablero -> tablero[x-1][(y*2)+2] == "     ") {
    //                 x -= 1;
    //                 y += 1;
    //                 pos = Posicion (x, y); //cambiar a metodo de pos (lo mismo para abajo)
    //                 return pos;
    //             } //else no se puede mover (?)
    //         } else {
    //             if (tablero -> tablero[x-1][(y*2)-2] == "     ") {
    //                 x -= 1;
    //                 y -= 1;
    //                 pos.set(x, y);
    //                 pos = Posicion (x, y);
    //                 return pos;
    //             } //else no se puede mover (?)
    //         }
    //     } else {
    //         if (y*2 < tablero -> getCentro().getY()) {
    //             if (tablero -> tablero[x+1][(y*2)+2] == "     ") {
    //                 x += 1;
    //                 y += 1;
    //                 pos = Posicion (x, y);
    //                 return pos;
    //             } //else no se puede mover (?)
    //         } else {
    //             if (tablero -> tablero[x+1][(y*2)-2] == "     ") {
    //                 x += 1;
    //                 y -= 1;
    //                 pos = Posicion (x, y);
    //                 return pos;
    //             } //else no se puede mover (?)
    //         }
    //     }
    // // x == centro <--------------------------------
    // } else if (x == tablero -> getCentro().getX()) {
    //     if (y*2 > tablero -> getCentro().getY()) {
    //         if (tablero -> tablero[x][(y*2)-2] == "     ") {
    //                 y -= 1;
    //                 pos = Posicion (x, y);
    //                 return pos;
    //         } //else no se puede mover (?)
    //     } else if (y*2 < tablero -> getCentro().getY()) {
    //         if (tablero -> tablero[x][(y*2)+2] == "     ") {
    //                 y += 1;
    //                 pos = Posicion (x, y);
    //                 return pos;
    //         } //else no se puede mover (?)
    //     }
    // // y == centro <--------------------------------
    // } else if (y*2 == tablero -> getCentro().getY()) {
    //     if (x > tablero -> getCentro().getX()) {
    //         if (tablero -> tablero[x-1][y*2] == "     ") {
    //                 x -= 1;
    //                 pos = Posicion (x, y);
    //                 return pos;
    //         } //else no se puede mover (?)
    //     } else if (x < tablero -> getCentro().getX()) {
    //         if (tablero -> tablero[x+1][y*2] == "     ") {
    //                 x += 1;
    //                 pos = Posicion (x, y);
    //                 return pos;
    //         } //else no se puede mover (?)
    //     }
    // }
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

void Personaje::setMapa(Mapa *tablero) {
    this -> tablero = tablero;
}