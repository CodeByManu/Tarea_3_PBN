#pragma once

class Posicion{
    private:
        int x;
        int y;
    public:
        // Metodos
        Posicion();
        Posicion(int x, int y);
        // Getters
        int getX();
        int getY();
        // Setters
        void set(int, int);
};