
default: bino

bino.o: src/bino.c
	gcc -c src/bino.c

bino: bino.o
	gcc -o bino bino.o

clean:
	rm -f bino.o
	rm -f bino
