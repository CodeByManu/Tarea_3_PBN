#include <iostream>
#include <string>
// #include <windows.h>

#include "juego.h"

Juego::Juego() {}

void Juego::jugar() {
    estado = 1;
}

int Juego::chequearGanador() {
    int counterE1 = 0;
    int counterE2 = 0;

    for (int i = 0; i < ejercito1.getCantidad(); i++) {
        if (ejercito1.personajes[i] -> estado == "vivo") counterE1++;
    }
    for (int i = 0; i < ejercito2.getCantidad(); i++) {
        if (ejercito2.personajes[i] -> estado == "vivo") counterE2++;
    }

    if (counterE1 == 0) {
        std::cout << "Ganador: Equipo 2" << std::endl;
        estado = 0;
        return 2;
    }
    else if (counterE2 == 0) {
        std::cout << "Ganador: Equipo 1" << std::endl;
        estado = 0;
        return 1;
    }
    else {
        //std::cout << "No hay ganador aun" << std::endl;
        return 0;
    }
}

int Juego::calcularTurno() {
    if (turno % 2 == 0) ejercitoActual = 0, ejercitoEnemigo = 1, indice++;
    else ejercitoActual = 1, ejercitoEnemigo = 0;
    turno++;
    return turno;
}

void Juego::turnoDes(Ejercito ejercitoX, Ejercito ejercitoY) {
    chequearGanador();
    if (indice >= ejercitoX.getCantidad()) indice = 0;
    if (ejercitoX.personajes[indice] -> estado == "vivo") {

        ejercitoX.personajes[indice] -> posPrevia = ejercitoX.personajes[indice] -> getPos();
        
        movimiento = ejercitoX.personajes[indice] -> moverse();
        rastro = Posicion(ejercitoX.personajes[indice] -> posPrevia.getX(), ejercitoX.personajes[indice] -> posPrevia.getY());

        // Necesario lo de abajo?
        std::cout << "Turno " << indice << ": " << ejercitoX.personajes[indice] -> getNombre() << " Posicion: (" << ejercitoX.personajes[indice] -> getPos().getX() << ", " << ejercitoX.personajes[indice] -> getPos().getY() << ")" << std::endl;
        Personaje *enemigo = llamarEnemigo(ejercitoX.personajes[indice] -> getPos(), ejercitoY);

        if (enemigo){
            if ((ejercitoX.personajes[indice] -> combatePendiente == 1) && (ejercitoX.personajes[indice] -> estado == "vivo") && (enemigo -> estado == "vivo")){
                combate(ejercitoX.personajes[indice], enemigo);
            }
        }
    mostrarMapa();
    }
}

int Juego::quienParte() {
    int media1 = ejercito1.getVelMedia(); std::cout << media1 << std::endl;
    int media2 = ejercito2.getVelMedia(); std::cout << media2 << std::endl;


    if ((media1 > media2) | (media1 == media2)) return 0;
    else return 1;
}

void Juego::mostrarMapa() {
    for (int i = 0; i < ancho; i++) std::cout << " _____";
    std::cout << std::endl;
    for(int i = 0; i < alto*2; i++){
        std::cout << '|';
        for(int j = 0; j < ancho; j++) {
            if (j == movimiento.getX() && (i == movimiento.getY()*2 || i == movimiento.getY()*2 + 1) ) {
            std::cout << "\033[48;2;255;63;63m" << "\033[38;2;204;204;204m" << tablero -> tablero[j][i] << "\033[0m" << '|';
            } else if (j == rastro.getX() && (i == rastro.getY()*2 || i == rastro.getY()*2 + 1)) {
            std::cout << "\033[48;2;255;125;125m" << "\033[38;2;204;204;204m" << tablero -> tablero[j][i] << "\033[0m" << '|';
            } else if (j == (tablero -> getCentro().getX()) && ((i == tablero -> getCentro().getY()) | (i == (tablero -> getCentro().getY() + 1)))) {
                std::cout << "\033[48;2;97;214;214m" << "\033[38;2;204;204;204m" << tablero -> tablero[j][i] << "\033[0m" << '|';
            } else std::cout << tablero -> tablero[j][i] << '|';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Juego::combate(Personaje *ataca, Personaje *defiende) {
    combateDef(ataca, defiende);
    ataca -> setPos(ataca -> posPrevia.getX(), ataca -> posPrevia.getY());
    tablero -> eliminarPersonaje(ataca);
    
    if (defiende -> estado == "muerto"){
        ataca -> setPos(defiende -> getPos().getX(), defiende -> getPos().getY());
        tablero -> eliminarPersonaje(defiende);
        tablero -> agregarPersonaje(ataca);
    }
}

void Juego::combateDef(Personaje *p1, Personaje *p2) {
    separador();
    std::cout << "Comienza pelea entre " << p1 -> getNombre() << " y " << p2 -> getNombre() << ":" << std::endl;
    std::cout << "La velocidad de " << p1 -> getNombre() << " es de " << p1 -> getVelocidad();
    std::cout << ", la de " << p2 -> getNombre() << " es de " << p2 -> getVelocidad();
    if (p1 -> getVelocidad() > p2 -> getVelocidad()) Juego::combateDes(p1, p2);
    else combateDes(p2, p1);
}

void Juego::combateDes(Personaje *primero, Personaje *segundo) {
    std::cout << ", comienza atacando " << primero -> getNombre() << std::endl;
    while ((primero -> getVida() || segundo -> getVida()) > 0){
        std::cout << primero -> getNombre() << " inflinge " << primero -> getDanio() << " de daño a " << segundo -> getNombre();
        segundo -> recibirAtaque(primero);
        if (segundo -> getVida() <= 0) {
            std::cout << ", vida restante: 0" << std::endl;
            segundo -> matar(segundo);
            break;
        }
        else std::cout << ", vida restante: " << segundo -> getVida() << std::endl;
        std::cout << segundo -> getNombre() << " inflinge " << segundo -> getDanio() << " de daño a " << primero -> getNombre();
        primero -> recibirAtaque(segundo);
        if (primero -> getVida() <= 0) {
            std::cout << ", vida restante: 0" << std::endl;
            primero -> matar(primero);
            break;
        }
        else std::cout << ", vida restante: " << primero -> getVida() << std::endl;
    }
    std::cout << "Combate finalizado, ha ganado ";
    if (primero -> getVida() > 0) std::cout << primero -> getNombre() << std::endl;
    else std::cout << segundo -> getNombre() << std::endl;
    separador();
}

int Juego::getEstado() {
    return estado;
}

void Juego::setMapa(Mapa *tablero) {
    this -> tablero = tablero;
    ancho = tablero -> getAncho();
    alto = tablero -> getAlto();
}

Personaje* Juego::llamarEnemigo(Posicion pos, Ejercito ejercitoRival) {
    for (int i = 0; i < ejercitoRival.getCantidad(); i++){
        if ((ejercitoRival.personajes[i] -> getPos().getX() == pos.getX()) && (ejercitoRival.personajes[i] -> getPos().getY() == pos.getY()) && (ejercitoRival.personajes[i] -> estado == "vivo")) {
            std::cout << "Enemigo encontrado: " << ejercitoRival.personajes[i] -> getNombre() << std::endl;
            return ejercitoRival.personajes[i];
        }
    }
    std::cout << "No se encontro ningun enemigo." << std::endl;
    return nullptr;
}

void Juego::separador(){
    for (int i = 0; i < tablero -> getAncho() * 5 + tablero -> getAncho(); i ++) std::cout << '=';
    std::cout << std::endl;
}

void Juego::bienvenidaJuego() {
    int ancho = tablero -> getAncho();
    separador();
    for (int i = 0; i < (ancho + 1 / 2); i ++) std::cout << " ";
    std::cout << "BIENVENIDO AL BATALLA MAS EPICA DE LA HISTORIA" << std::endl;
    separador();
}
