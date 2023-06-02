CC = g++
flags = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
name = tarea_3
source = main
hpath = ../clases/
objects = posicion.o personaje.o mapa.o juego.o ejercito.o

all: clean run

$(name): $(source).o $(objects)
	$(CC) $(flags) $^ -o $@
	
run: $(name)
	./$(name)	

$(objects): %.o: $(hpath)%.cpp
	$(CC) $(flags) -c -o $@ $<

$(source).o: $(source).cpp
	$(CC) $(flags) -c -o $@ $<

clean:
	del -f *.o $(name).exe