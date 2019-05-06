all: listTest.out
	echo "Build Done!"
listTest.out: main.o list.o
	gcc -std=c89 main.o list.o
main.o: main.c list.h
	gcc -c -Wall -std=c89 main.c
list.o: list.c list.h
	gcc -c -Wall -std=c89 list.c
clean:
	rm -r *.out *.o
