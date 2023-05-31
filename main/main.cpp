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

    Personaje ***ejercitos = new Personaje**[2];
    ejercitos[0] = ejercito1;
    ejercitos[1] = ejercito2;

    int whoStart = juego.quienParte(ejercito1, n1, ejercito2, n2); 
    int turno = 0;
    int e = 0;
    int o = 1;

    if (whoStart == 1){
        cout << "Empieza el ejercito 1" << endl;
        cout << "Turno: " << turno << endl;
        while (1){
            if (juego.chequearGanador(ejercitos[0], n1, ejercitos[1], n2) == (1 || 0)) break;
            if (turno % 2 == 0) e = 0, o = 1;
            else e = 1, o = 0;

            if (turno > n1) turno = 0;

            int xAux = ejercitos[e][turno] -> getPos().getX();
            int yAux = ejercitos[e][turno] -> getPos().getY();

            ejercitos[e][turno] -> moverse();
            Personaje *enemigo = juego.llamarEnemigo(ejercitos[e][turno] -> getPos(), ejercitos[1], n2);
            if (ejercitos[e][turno] -> combatePendiente == 1 && ejercitos[e][turno] -> estado == "vivo" && enemigo -> estado == "vivo"){
                juego.combate(ejercitos[e][turno], enemigo);

                ejercitos[e][turno] -> pos.set(xAux, yAux);
                tablero -> eliminarPersonaje(ejercitos[0][turno]);
                
                if (enemigo -> estado == "muerto"){
                    ejercitos[e][turno] -> pos.set(enemigo -> pos.getX(), enemigo -> pos.getY());
                    tablero -> eliminarPersonaje(enemigo);
                    tablero -> agregarPersonaje(ejercitos[e][turno]);
                }       
            }
            turno++;
            juego.mostrarMapa();
        }
    }
    // int xAux = ejercito2[6] -> getPos().getX();
    // int yAux = ejercito2[6] -> getPos().getY();
    
    // ejercito2[6] -> moverse();
    // if (ejercito2[6] -> combatePendiente == 1 && ejercito2[6] -> estado == "vivo"){
    //     Personaje *enemigo = juego.llamarEnemigo(ejercito2[6] -> getPos(), ejercito1, n1);
    //     juego.combate(ejercito2[6], enemigo);

    //     ejercito2[6] -> pos.set(xAux, yAux);
    //     tablero -> eliminarPersonaje(ejercito2[6]);
        
    //     if (enemigo -> estado == "muerto"){
    //         ejercito2[6] -> pos.set(enemigo -> pos.getX(), enemigo -> pos.getY());
    //         tablero -> eliminarPersonaje(enemigo);
    //         tablero -> agregarPersonaje(ejercito2[6]);
    //     }

    //     cout << enemigo -> getNombre() << " | " << enemigo -> getVida() << ":" << enemigo -> estado << endl;
    //     cout << ejercito2[6] -> getNombre() << " | " << ejercito2[6] -> getVida() << ":" << ejercito2[6] -> estado << endl;
    // }



    // if (ejercito1[3] -> getPos().getX() == ejercito2[4] -> getPos().getX() && ejercito1[3] -> getPos().getY() == ejercito2[4] -> getPos().getY())

    juego.mostrarMapa();

    // tablero -> eliminarPersonaje(ejercito1[0]);

    for (int i = 0; i < n1; i++) delete ejercito1[i];
    delete[] ejercito1;

    for (int i = 0; i < n2; i++) delete ejercito2[i];
    delete[] ejercito2;

    soldados.close();
    return 0;
}