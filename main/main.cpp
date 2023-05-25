// #include "../clases/hfiles.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
// #include "../clases/personaje.h"
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
    
    // Ejercito 1
    soldados >> n1;
    Personaje **ejercito1 = new Personaje*[n1];
    for (int i = 0; i < n1; i++) {
        string linea, nombre;
        int vida, daño, velocidad, px, py;

        getline(soldados, linea, ','); linea.erase(remove(linea.begin(), linea.end(), '\n'), linea.cend()); nombre = linea;
        getline(soldados, linea, ','); vida = stoi(linea);
        getline(soldados, linea, ','); daño = stoi(linea);
        getline(soldados, linea, ','); velocidad = stoi(linea);
        getline(soldados, linea, ','); px = stoi(linea);
        getline(soldados, linea); py = stoi(linea);
        
        Posicion coord(px, py);
        ejercito1[i] = new Personaje(nombre, vida, daño, velocidad, coord);
        tablero -> agregarPersonaje(ejercito1[i], "1");
    }

    // Ejercito 2
    soldados >> n2;
    Personaje **ejercito2 = new Personaje*[n2];
    for (int i = 0; i < n1; i++) {
        string linea, nombre;
        int vida, daño, velocidad, px, py;

        getline(soldados, linea, ','); linea.erase(remove(linea.begin(), linea.end(), '\n'), linea.cend()); nombre = linea;
        getline(soldados, linea, ','); vida = stoi(linea);
        getline(soldados, linea, ','); daño = stoi(linea);
        getline(soldados, linea, ','); velocidad = stoi(linea);
        getline(soldados, linea, ','); px = stoi(linea);
        getline(soldados, linea); py = stoi(linea);
        
        Posicion coord(px, py);
        ejercito2[i] = new Personaje(nombre, vida, daño, velocidad, coord);
        tablero -> agregarPersonaje(ejercito2[i], "2");
    }

    Juego juego;
    juego.setMapa(tablero);
    juego.mostrarMapa();

    // tablero.eliminarPersonaje(ejercito1[0]);

    for (int i = 0; i < n1; i++) delete ejercito1[i];
    delete[] ejercito1;

    soldados.close();
    return 0;
}