# Write this Makefile

myas: main.o check.o trans.o
	gcc -o myas main.o check.o trans.c

main.o: main.c
	gcc -c main.c 
check.o: check.c 
	gcc -c check.c
trans.o: trans.c
	gcc -c trans.c
clean:
	rm -rf main.o check.o trans.o

