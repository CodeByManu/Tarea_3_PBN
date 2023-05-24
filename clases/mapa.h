#include "personaje.h"

class Mapa {
    private:
        int ancho;
        int alto;
    public:
        std::string **tablero;
        Mapa(int, int);
        void crearMapa(int, int);
        void agregarPersonaje(Personaje);
        void eliminarPersonaje(Personaje*);
        ~Mapa();
};