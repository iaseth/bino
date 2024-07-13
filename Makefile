
default: bino

bino.o: bino.c
	gcc -c bino.c

bino: bino.o
	gcc -o bino bino.c

clean:
	rm -f bino.o
	rm -f bino
