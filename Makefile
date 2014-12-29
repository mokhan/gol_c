default: src/*.c src/*.h
	rm -fr bin
	mkdir -p bin
	gcc -std=c99 -Wall -o bin/gol src/gol.c src/main.c
	./bin/gol
