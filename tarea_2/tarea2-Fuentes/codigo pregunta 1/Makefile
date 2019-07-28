all:main

main:main.o functions.o
	gcc -Wall -o main main.o functions.o
main.o:main.c functions.o
	gcc -Wall -c main.c
functions.o:functions.c
	gcc -Wall -c functions.c

clean:
	rm *.o main 
