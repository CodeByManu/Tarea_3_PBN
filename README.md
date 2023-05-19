# **Tarea_3_PBN**

## **Clases:**

- **Posicion:** int x, int y
- **Personaje:** string name, int health, int attack, int speed, Posicion pos (*Posicion es la Clase de arriba*)
- **Mapa:** int ancho, int alto
- **Juego:** representa el juego

---

## **Métodos:**

- ### **Posicion**

    - **int getX():** Getter de coordenada X
    - **int getY():** Getter de coordenada Y
    - **void set(int x, int y):** Modifica las coordenadas (*Setter*)

- ### **Personaje**

    - **int attack():** retorna el daño que se hará al oponente
    - **void recibirAtaque(Personaje enemigo):** Recibe un ataque enemigo
    - **moverse():** mueve al personaje según mecanicas del juego

- ### **Mapa**

    - **crearMapa(int ancho, int alto):** crea un mapa de ancho x alto
    - **void agregarPersonaje(Personaje personaje):** agrega un personaje en el mapa
    - **void eliminarPersonaje(Personaje personaje):** elimina un personaje del mapa

- ### **Juego**

    - **void jugar():** inicia el juego
    - **void chequearGanador():** chequea si ha ganado alguno de los ejercitos
    - **void mostrarMapa():** muestra en la consola el mapa del juego y con sus personajes
    - **void combate(Personaje p1, Personaje p2):** Simula una pelea entre dos personajes

---

## **Mecánica del Juego:**
