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
    Personaje **ejercito1Aux = new Personaje*[n1];
    Ejercito ejercito1(ejercito1Aux);
    ejercito1.setCantidad(n1);
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
        ejercito1.personajes[i] = new Personaje(nombre, vida, danio, velocidad, coord);
        ejercito1.personajes[i] -> ejercito = "1";
        ejercito1.personajes[i] -> setMapa(tablero);
        tablero -> agregarPersonaje(ejercito1.personajes[i]);
    }

    // Ejercito 2
    soldados >> n2;
    Personaje **ejercito2Aux = new Personaje*[n2];
    Ejercito ejercito2(ejercito2Aux);
    ejercito2.setCantidad(n2);
    for (int i = 0; i < n2; i++) {
        string linea, nombre;
        int vida, danio, velocidad, px, py;

        getline(soldados, linea, ','); linea.erase(remove(linea.begin(), linea.end(), '\n'), linea.end()); nombre = linea;
        getline(soldados, linea, ','); vida = stoi(linea);
        getline(soldados, linea, ','); danio = stoi(linea);
        getline(soldados, linea, ','); velocidad = stoi(linea);
        getline(soldados, linea, ','); px = stoi(linea);
        getline(soldados, linea); py = stoi(linea);
        
        Posicion coord(px, py);
        ejercito2.personajes[i] = new Personaje(nombre, vida, danio, velocidad, coord);
        ejercito2.personajes[i] -> ejercito = "2";
        ejercito2.personajes[i] -> setMapa(tablero);
        tablero -> agregarPersonaje(ejercito2.personajes[i]);
    }

    // Juego
    Juego juego;
    juego.setMapa(tablero);
    juego.ejercito1 = ejercito1;
    juego.ejercito2 = ejercito2;
    juego.mostrarMapa();

    Ejercito *ejercitos = new Ejercito[2];
    ejercitos[0] = juego.ejercito1;
    ejercitos[1] = juego.ejercito2;

    juego.jugar();

    while (juego.getEstado() == 1) {
        
    }


    int whoStart = juego.quienParte();
    
    if (whoStart == 1){
        cout << "Empieza el ejercito 1" << endl;
        juego.jugar();

        while (juego.getEstado() == 1){
            juego.turnoDes();
            juego.calcularTurno();
        }
    }


    for (int i = 0; i < n1; i++) delete ejercito1Aux[i];
    delete[] ejercito1Aux;
    for (int i = 0; i < n2; i++) delete ejercito2Aux[i];
    delete[] ejercito2Aux;
    delete[] ejercitos;

    soldados.close();
    return 0;
}






/* 

e1 | e1
0       0
1       1
2       2

 */