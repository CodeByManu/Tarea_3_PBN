CC=g++
flags=-std=c++11 #-Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
name=tarea_3#TODO Ponerle nombre al programa
source=main#TODO ponerle nombre al codigo
hpath=../clases/

$(name): $(source).o posicion.o personaje.o mapa.o juego.o
	$(CC) $(flags) $(source).o posicion.o personaje.o mapa.o juego.o -o $(name)
	
run: $(name)
	./$(name)
	
all: clean run
	
posicion.o: ${hpath}posicion.cpp
	$(CC) $(flags) -c -o posicion.o ${hpath}posicion.cpp

personaje.o: ${hpath}personaje.cpp
	$(CC) $(flags) -c -o personaje.o ${hpath}personaje.cpp

mapa.o: ${hpath}mapa.cpp
	$(CC) $(flags) -c -o mapa.o ${hpath}mapa.cpp

juego.o: ${hpath}juego.cpp
	$(CC) $(flags) -c -o juego.o ${hpath}juego.cpp

$(source).o: $(source).cpp
	$(CC) $(flags) -c -o $(source).o $(source).cpp

clean:
	del -f *.o $(name).exe