#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "../clases/juego.h"

using namespace std;

int main() {

    ifstream soldados;
    int n1, n2;
    string tx, ty;
    
    soldados.open("../input-data/soldados.txt");

    // Tablero
    getline(soldados, tx, ','); int x = stoi(tx);
    getline(soldados, ty); int y = stoi(ty);
    Mapa *tablero = new Mapa(x, y);
    tablero -> crearMapa(x, y);
    Posicion centro((tablero -> getAncho())/2, (tablero -> getAlto()-1));
    tablero -> setCentro(centro);
    
    // Ejercito 1
    soldados >> n1;
    Personaje **ejercito1 = new Personaje*[n1];
    for (int i = 0; i < n1; i++) {
        string linea, nombre;
        int vida, danio, velocidad, px, py;
        //remove() lleva al final todos los elementos que se quieren borrar y retorna un iterador
        //.erase borra todo lo que se le entrega, pero de parametros recibe iteradores, por eso el buen funcionamiento del modismo remove-erase
        getline(soldados, linea, ','); linea.erase(remove(linea.begin(), linea.end(), '\n'), linea.end()); nombre = linea;
        getline(soldados, linea, ','); vida = stoi(linea);
        getline(soldados, linea, ','); danio = stoi(linea);
        getline(soldados, linea, ','); velocidad = stoi(linea);
        getline(soldados, linea, ','); px = stoi(linea);
        getline(soldados, linea); py = stoi(linea);
        
        Posicion coord(px, py);
        ejercito1[i] = new Personaje(nombre, vida, danio, velocidad, coord);
        ejercito1[i] -> ejercito = "1";
        ejercito1[i] -> setMapa(tablero); //factible? o mejor crear coordenada centro x c/personaje?
        tablero -> agregarPersonaje(ejercito1[i]);
    }

    // Ejercito 2
    soldados >> n2;
    Personaje **ejercito2 = new Personaje*[n2];
    for (int i = 0; i < n1; i++) {
        string linea, nombre;
        int vida, danio, velocidad, px, py;

        getline(soldados, linea, ','); linea.erase(remove(linea.begin(), linea.end(), '\n'), linea.end()); nombre = linea;
        getline(soldados, linea, ','); vida = stoi(linea);
        getline(soldados, linea, ','); danio = stoi(linea);
        getline(soldados, linea, ','); velocidad = stoi(linea);
        getline(soldados, linea, ','); px = stoi(linea);
        getline(soldados, linea); py = stoi(linea);
        
        Posicion coord(px, py);
        ejercito2[i] = new Personaje(nombre, vida, danio, velocidad, coord);
        ejercito2[i] -> ejercito = "2";
        ejercito2[i] -> setMapa(tablero);
        tablero -> agregarPersonaje(ejercito2[i]);
    }

    Juego juego;
    juego.setMapa(tablero);
    juego.mostrarMapa();

    cout << ejercito2[2] -> getPos().getX() << ejercito2[2] -> getPos().getY() << tablero -> getCentro().getY() << endl;
    ejercito2[2] -> moverse();
    tablero -> agregarPersonaje(ejercito2[2]);

    juego.mostrarMapa();

    juego.combate(ejercito1[0], ejercito2[0]);

    // tablero -> eliminarPersonaje(ejercito1[0]);

    for (int i = 0; i < n1; i++) delete ejercito1[i];
    delete[] ejercito1;

    soldados.close();
    return 0;
}