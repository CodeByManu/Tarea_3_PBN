CC=g++
flags=-std=c++11#-Wundef -Werror -Wall
name=#TODO Ponerle nombre al programa
source=main#TODO ponerle nombre al codigo

$(name): $(source).o posicion.o personaje.o mapa.o juego.o
	$(CC) $(flags) $(source).o posicion.o personaje.o mapa.o juego.o -o $(name)
	
run: $(name)
	./$(name)
	
all: clean run
	
posicion.o: posicion.cpp
	$(CC) $(flags)   -c -o posicion.o posicion.cpp

personaje.o: personaje.cpp
	$(CC) $(flags)   -c -o posicion.o posicion.cpp

mapa.o: mapa.cpp
	$(CC) $(flags)   -c -o posicion.o posicion.cpp

juego.o: juego.cpp
	$(CC) $(flags)   -c -o posicion.o posicion.cpp

$(source).o: $(source).cpp
	$(CC) $(flags)  -c -o $(source).o $(source).cpp


clean:
	rm -f *.o $(name)
