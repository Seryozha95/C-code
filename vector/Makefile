CC=gcc
CFLAG=-Wall -pedantic -ansi

Main: main.c Vector
	$(CC) $(CFLAG) main.c vector.o -o main

Vector:
	$(CC) $(CFLAG) -c ./vector/vector.c -o vector.o

.PHONY: clean run

clean:
	rm *.o main

run:
	./vector