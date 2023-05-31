#include <iostream>
#include <windows.h>

#include "juego.h"

Juego::Juego():tablero{tablero} {}

void Juego::jugar() {
    // TODO
}

void Juego::chequearGanador() {
    int muertesE1 = 0;
    int muertesE2 = 0;

    // for n in ejercitoX -> if muertesEX == ejercitoX.length -> ejercitoX pierde
}

int Juego::calcularTurno() {
    
}

int Juego::quienParte() {
    float suma1 = 0;
    for (int i = 0; i < n1; i++) suma1 += ejercito1[i] -> getVelocidad();
    float suma2 = 0;
    for (int i = 0; i < n2; i++) suma2 += ejercito2[i] -> getVelocidad();

    if ((suma1/n1 > suma2/n2) | (suma1/n1 == suma2/n2)) return 1;
    else return 2;
    
}

void Juego::mostrarMapa() {
    for (int i = 0; i < ancho; i++) std::cout << " _____";
    std::cout << std::endl;
    for(int i = 0; i < alto*2; i++){
        std::cout << '|';
        for(int j = 0; j < ancho; j++) {
            if (j == (tablero -> getCentro().getX()) && (i == tablero -> getCentro().getY() | i == (tablero -> getCentro().getY() + 1))) {
                std::cout << "\033[48;2;97;214;214m" << "\033[38;2;204;204;204m" << tablero -> tablero[j][i] << "\033[0m" << '|';
            } else std::cout << tablero -> tablero[j][i] << '|';
        }
        std::cout << std::endl;
    }
}

void Juego::combate(Personaje *ataca, Personaje *defiende) {
    // int xAux = ataca -> posPrevia.getX();
    // int yAux = ataca -> posPrevia.getY();
    Posicion posPrevia(ataca -> posPrevia.getX(), ataca -> posPrevia.getY());

    
    // ataca -> moverse(); //hacer fuera de metodo <-------------------
    // if (ejercito2[6] -> combatePendiente == 1){
        // Personaje *defiende = llamarEnemigo(ejercito2[6] -> getPos(), ejercito1, n1);
        combateDef(ataca, defiende);
        std::cout << ataca -> getPos().getX() << ataca -> getPos().getY() << std::endl;
        ataca -> setPos(posPrevia);
        std::cout << ataca -> getPos().getX() << ataca -> getPos().getY() << std::endl;
        tablero -> eliminarPersonaje(ataca);
        
        if (defiende -> estado == "muerto"){
            ataca -> getPos().set(defiende -> getPos().getX(), defiende -> getPos().getY());
            tablero -> eliminarPersonaje(defiende);
            tablero -> agregarPersonaje(ataca);
        }
    // }
}

void Juego::combateDef(Personaje *p1, Personaje *p2) {
    std::cout << "Comienza pelea entre " << p1 -> getNombre() << " y " << p2 -> getNombre() << ":" << std::endl;
    std::cout << "La velocidad de " << p1 -> getNombre() << " es de " << p1 -> getVelocidad();
    std::cout << ", la de " << p2 -> getNombre() << " es de " << p2 -> getVelocidad();
    if (p1 -> getVelocidad() > p2 -> getVelocidad()) Juego::combateDes(p1, p2);
    else combateDes(p2, p1);
}

void Juego::combateDes(Personaje *primero, Personaje *segundo) {
    std::cout << ", comienza atacando " << primero -> getNombre() << std::endl;
    while ((primero -> getVida() | segundo -> getVida()) > 0){
        std::cout << primero -> getNombre() << " inflinge " << primero -> getDanio() << " de daño a " << segundo -> getNombre();
        segundo -> recibirAtaque(primero);
        if (segundo -> getVida() <= 0) {
            std::cout << ", vida restante: 0" << std::endl;
            tablero -> eliminarPersonaje(segundo);
            segundo -> matar(segundo);
            tablero -> agregarPersonaje(primero);
            break;
        }
        else std::cout << ", vida restante: " << segundo -> getVida() << std::endl;
        std::cout << segundo -> getNombre() << " inflinge " << segundo -> getDanio() << " de daño a " << primero -> getNombre();
        primero -> recibirAtaque(segundo);
        if (primero -> getVida() <= 0) {
            std::cout << ", vida restante: 0" << std::endl;
            tablero -> eliminarPersonaje(primero);
            primero -> matar(primero);
            tablero -> agregarPersonaje(segundo);

            break;
        }
        else std::cout << ", vida restante: " << primero -> getVida() << std::endl;
    }
    std::cout << "Combate finalizado, ha ganado ";
    if (primero -> getVida() > 0) std::cout << primero -> getNombre() << std::endl;
    else std::cout << segundo -> getNombre() << std::endl;
}

void Juego::setMapa(Mapa *tablero) {
    this -> tablero = tablero;
    ancho = tablero -> getAncho();
    alto = tablero -> getAlto();
}

Personaje* Juego::llamarEnemigo(Posicion pos, Personaje **equipo, int n) {
    for (int i = 0; i < n; i++){
        if (equipo[i] -> getPos().getX() == pos.getX() && equipo[i] -> getPos().getY() == pos.getY()) {
            std::cout << "Enemigo encontrado: " << equipo[i] -> getNombre() << std::endl;
            return equipo[i];
        }
    }
}