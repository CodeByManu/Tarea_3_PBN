// #include "../clases/hfiles.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "../clases/personaje.h"
// #include "../clases/mapa.h"

using namespace std;

int main() {

    ifstream soldados;
    int n1, n2;
    string tx, ty;

    soldados.open("../input-data/soldados_short.txt");

    // Tablero
    getline(soldados, tx, ','); int x = stoi(tx);
    getline(soldados, ty); int y = stoi(ty);
    // Mapa tablero(x, y);
    
    soldados >> n1;
    Personaje ejercito1[n1];
    for (int i = 0; i < n1; i++) {
        string linea, nombre;
        int vida, daño, velocidad, px, py;

        getline(soldados, linea, ','); nombre = linea;
        getline(soldados, linea, ','); vida = stoi(linea);
        getline(soldados, linea, ','); daño = stoi(linea);
        getline(soldados, linea, ','); velocidad = stoi(linea);
        getline(soldados, linea, ','); px = stoi(linea);
        getline(soldados, linea); py = stoi(linea);
        
        Posicion coord(px, py);
        ejercito1[i] = Personaje(nombre, vida, daño, velocidad, coord);
        // ubicar personaje en mapa

    }
    
    soldados >> n2;
    Personaje ejercito2[n2];
    for (int i = 0; i < n1; i++) {
        string linea, nombre;
        int vida, daño, velocidad, px, py;

        getline(soldados, linea, ','); nombre = linea;
        getline(soldados, linea, ','); vida = stoi(linea);
        getline(soldados, linea, ','); daño = stoi(linea);
        getline(soldados, linea, ','); velocidad = stoi(linea);
        getline(soldados, linea, ','); px = stoi(linea);
        getline(soldados, linea); py = stoi(linea);
        
        Posicion coord(px, py);
        ejercito2[i] = Personaje(nombre, vida, daño, velocidad, coord);
        // ubicar personaje en mapa
    }

    soldados.close();
    return 0;
}