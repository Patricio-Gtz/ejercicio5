HEADERS = funciones.h

default: tarea5.out

tarea5.o: tarea5.c $(HEADERS)
	gcc -c tarea5.c -o tarea5.o

tarea5.out: tarea5.o
	gcc tarea5.o -o tarea5.out

clean:
	-rm -f tarea5.o
	-rm -f tarea5.out
