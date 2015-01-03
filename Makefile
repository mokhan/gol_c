SHELL=/bin/sh
CFLAGS=-Wall -g -std=c99

all: src/*.c src/*.h
	rm -fr bin
	mkdir -p bin
	$(CC) $(CFLAGS) -std=c99 -o bin/game_of_life src/main.c src/world.c src/cell.c
	./bin/game_of_life

clean:
	rm -fr bin

init:
	mkdir -p bin

test: cell.o world.o world_test.o
	$(CC) $(CFLAGS) -o bin/test_game_of_life src/world.o src/cell.o src/world_test.o
	./bin/test_game_of_life

cell.o: src/cell.c src/cell.h
	$(CC) $(CFLAGS) -c src/cell.c

world.o: src/world.c src/world.h
	$(CC) $(CFLAGS) -c src/world.c

world_test.o: src/world_test.c src/world.h
	$(CC) $(CFLAGS) -c src/world_test.c
