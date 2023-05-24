// #include "../clases/hfiles.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
// #include "../clases/personaje.h"
#include "../clases/mapa.h"

using namespace std;

int main() {

    ifstream soldados;
    int n1, n2;
    string tx, ty;

    soldados.open("../input-data/soldados_short.txt");

    // Tablero
    getline(soldados, tx, ','); int x = stoi(tx);
    getline(soldados, ty); int y = stoi(ty);
    Mapa tablero(x, y);
    tablero.crearMapa(x, y);
    
    cout << " _____ _____ _____ _____ _____ _____ _____" << endl;
    for(int i = 0; i < y*2; i++){
        cout << '|';
        for(int j = 0; j < x; j++){
            cout << tablero.tablero[j][i] << '|';
        }
        cout << endl;
    }

    
    soldados >> n1;
    Personaje ejercito1[n1];
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
        ejercito1[i] = Personaje(nombre, vida, daño, velocidad, coord);
        // ubicar personaje en mapa
        // tablero.agregarPersonaje(ejercito1[i]);
    }

    soldados >> n2;
    Personaje ejercito2[n2];
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
        ejercito2[i] = Personaje(nombre, vida, daño, velocidad, coord);
        // ubicar personaje en mapa
        // tablero.agregarPersonaje(ejercito2[i]);
    }

    // tablero.agregarPersonaje(ejercito1[0]);
    // tablero.agregarPersonaje(ejercito2[0]);

    cout << " _____ _____ _____ _____ _____ _____ _____" << endl;
    for(int i = 0; i < y*2; i++){
        cout << '|';
        for(int j = 0; j < x; j++){
            if (i == 2 && j == 2) cout << "test |";
            else cout << tablero.tablero[j][i] << '|';
        }
        cout << endl;
    }
    cout << ejercito1[0].getNombre() << endl;

    soldados.close();
    return 0;
}