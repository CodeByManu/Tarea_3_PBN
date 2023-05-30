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

    char ejercitoAux = tablero -> tablero[x][y*2 + 1][2];

    int xAux = x;
    int yAux = y;

    int xCentro = tablero -> getCentro().getX();
    int yCentro = tablero -> getCentro().getY();

    if (x > xCentro) x--;
    else if (x < xCentro) x++;
    if (y*2 > yCentro) y--;
    else if (y*2 < yCentro) y++;

    if (tablero -> tablero[x][y*2] == "     ") {
        tablero -> eliminarPersonaje(this);
        this -> pos.set(x, y);
        tablero -> agregarPersonaje(this);
        return pos;
    } else {
        if (tablero -> tablero[x][y*2 + 1][2] != ejercitoAux) {
            this -> pos.set(x, y);
            this -> combatePendiente = 1;
            return pos;
        } else {
            if (tablero -> tablero[xAux][y*2] == "     "){
                tablero -> eliminarPersonaje(this);
                this -> pos.set(xAux, y);
                // tablero -> agregarPersonaje(this);
                return pos;
            } else {
                this -> pos.set(xAux, yAux);
                return pos;
            }
        }
    }
}

std::string Personaje::getNombre() {
    return nombre;
}

void Personaje::matar(Personaje* personaje){
    this -> estado = "muerto";
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

Personaje::~Personaje(){}