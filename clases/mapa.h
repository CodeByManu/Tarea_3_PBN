#include "personaje.h"

class Mapa {
    private:
        int ancho;
        int alto;
    public:
        std::string **tablero;
        Mapa();
        Mapa(int, int);
        void crearMapa(int, int);
        void agregarPersonaje(Personaje*, std::string); // Agruegue parametro string para poner el # de ejercito (nose si se puede)
        void eliminarPersonaje(Personaje*);
        int getAncho(); // Se puede?
        int getAlto(); // Se puede?
        ~Mapa();
};