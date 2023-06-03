#include "../clases/hfiles.h"

using namespace std;

int main() {

    ifstream soldados;
    int n1, n2;
    string tx, ty, string_aux;
    
    soldados.open("../input-data/soldados_windows.txt");

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

        getline(soldados, linea, ',');
        if (i == 0) nombre = linea.substr(1, linea.length()); // Windows = substr(1, linea.length()) || Linux = substr(2, linea.length())
        // Esto ya que cada OS formatea a su manera los .txt (\n\n o \n (o con \r)) y causado por traslado de archivos (Windows -> Linux)
        else nombre = linea;
        // Solo ocurria con el primer nombre de cada ejercito
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

        getline(soldados, linea, ',');
        if (i == 0) nombre = linea.substr(2, linea.length()); // Windows = substr(1, linea.length()) || Linux = substr(2, linea.length())
        // Esto ya que cada OS formatea a su manera los .txt (\n\n o \n (o con \r)) y causado por traslado de archivos (Windows -> Linux)
        else nombre = linea;
        // Solo ocurria con el primer nombre de cada ejercito
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
    juego.bienvenidaJuego();
    juego.mostrarMapa();

    cout << endl << "Así queda la distribución de los soldados... Enter para continuar." << endl;
    cin.get();

    Ejercito *ejercitos = new Ejercito[2];
    ejercitos[0] = juego.ejercito1;
    ejercitos[1] = juego.ejercito2;

    juego.jugar();

    juego.ejercitoActual = juego.quienParte();

    if (juego.ejercitoActual == 0) juego.ejercitoEnemigo = 1;
    else juego.ejercitoEnemigo = 0;
    
    cout << "Empieza el ejercito " << juego.ejercitoActual + 1 << endl;
    juego.jugar();

    while (juego.getEstado() == 1){
        juego.turnoDes(ejercitos[juego.ejercitoActual], ejercitos[juego.ejercitoEnemigo]);
        juego.calcularTurno();
    }

    cout << " ----- EL VENCEDOR ES ... (Enter para revelar el misterio) -----";
    cin.get();
    if (juego.chequearGanador() == 1) cout << "¡¡EJERCITO 1!!" << endl;
    else cout << "¡¡EJERCITO 2!!" << endl;

    for (int i = 0; i < n1; i++) delete ejercito1Aux[i];
    delete[] ejercito1Aux;
    for (int i = 0; i < n2; i++) delete ejercito2Aux[i];
    delete[] ejercito2Aux;
    delete[] ejercitos;

    soldados.close();
    return 0;
}