#include "posicion.h"

Posicion::Posicion(int x, int y) {
    this -> x = x;
    this -> y = y;
}

int Posicion::getX() {
    return x;
}

int Posicion::getY() {
    return y;
}

void Posicion::set(int x, int y) {
    this -> x = x;
    this -> y = y;
}