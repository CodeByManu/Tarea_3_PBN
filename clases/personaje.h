#include <string>

class Personaje{
    Personaje::Personaje(std::string, int, int, int, Posicion);

    int ataque();

    void recibirAtaque(Personaje*);

    void moverse(); //Que tipo tiene que ser? (void para que funcionara nomas)
};