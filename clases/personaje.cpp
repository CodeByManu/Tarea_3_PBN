#include "personaje.h"
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
    //x, y != centro <--------------------------------
    if ((x != tablero -> getCentro().getX()) && (y*2 != tablero -> getCentro().getY())) {
        if (x > tablero -> getCentro().getX()) {
            if (y*2 < tablero -> getCentro().getY()) {
                if (tablero -> tablero[x-1][(y*2)+2] == "     ") {
                    x -= 1;
                    y += 1;
                    pos = Posicion (x, y); //cambiar a metodo de pos (lo mismo para abajo)
                    return pos;
                } //else no se puede mover (?)
            } else {
                if (tablero -> tablero[x-1][(y*2)-2] == "     ") {
                    x -= 1;
                    y -= 1;
                    pos.set(x, y);
                    pos = Posicion (x, y);
                    return pos;
                } //else no se puede mover (?)
            }
        } else {
            if (y*2 < tablero -> getCentro().getY()) {
                if (tablero -> tablero[x+1][(y*2)+2] == "     ") {
                    x += 1;
                    y += 1;
                    pos = Posicion (x, y);
                    return pos;
                } //else no se puede mover (?)
            } else {
                if (tablero -> tablero[x+1][(y*2)-2] == "     ") {
                    x += 1;
                    y -= 1;
                    pos = Posicion (x, y);
                    return pos;
                } //else no se puede mover (?)
            }
        }
    // x == centro <--------------------------------
    } else if (x == tablero -> getCentro().getX()) {
        if (y*2 > tablero -> getCentro().getY()) {
            if (tablero -> tablero[x][(y*2)-2] == "     ") {
                    y -= 1;
                    pos = Posicion (x, y);
                    return pos;
            } //else no se puede mover (?)
        } else if (y*2 < tablero -> getCentro().getY()) {
            if (tablero -> tablero[x][(y*2)+2] == "     ") {
                    y += 1;
                    pos = Posicion (x, y);
                    return pos;
            } //else no se puede mover (?)
        }
    // y == centro <--------------------------------
    } else if (y*2 == tablero -> getCentro().getY()) {
        if (x > tablero -> getCentro().getX()) {
            if (tablero -> tablero[x-1][y*2] == "     ") {
                    x -= 1;
                    pos = Posicion (x, y);
                    return pos;
            } //else no se puede mover (?)
        } else if (x < tablero -> getCentro().getX()) {
            if (tablero -> tablero[x+1][y*2] == "     ") {
                    x += 1;
                    pos = Posicion (x, y);
                    return pos;
            } //else no se puede mover (?)
        }
    }
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