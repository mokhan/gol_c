SHELL=/bin/sh
CFLAGS=-Wall -g -std=c99
objects=cell.o world.o
test_objects=world_test.o
exe=./bin/game_of_life
test_exe=./bin/game_of_life_test

all: $(objects) main.o
	$(CC) $(CFLAGS) -o bin/game_of_life $(objects) main.o
	$(exe)

clean:
	mkdir -p bin
	rm -fr $(exe) $(test_exe) $(objects) $(test_objects)

test: $(objects) $(test_objects)
	$(CC) $(CFLAGS) -o $(test_exe) $(objects) $(test_objects)
	$(test_exe)

main.o: src/main.c src/world.h
	$(CC) $(CFLAGS) -c src/main.c

cell.o: src/cell.c src/cell.h
	$(CC) $(CFLAGS) -c src/cell.c

world.o: src/world.c src/world.h
	$(CC) $(CFLAGS) -c src/world.c

world_test.o: src/world_test.c src/world.h
	$(CC) $(CFLAGS) -c src/world_test.c
