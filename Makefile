SHELL=/bin/sh
CFLAGS=-Wall -g -std=c99 -Isrc
objects=cell.o world.o
test_objects=world_test.o test_main.o
exe=./bin/game_of_life
test_exe=./bin/game_of_life_test

all: $(objects) main.o
	$(CC) $(CFLAGS) -o $(exe) $(objects) main.o
	$(exe)

clean:
	rm -fr $(exe) $(test_exe) $(objects) main.o $(test_objects) test_main.o

test: $(objects) $(test_objects)
	$(CC) $(CFLAGS) -o $(test_exe) $(objects) $(test_objects)
	$(test_exe)

main.o: src/main.c src/world.h
	$(CC) $(CFLAGS) -c src/main.c

cell.o: src/cell.c src/cell.h
	$(CC) $(CFLAGS) -c src/cell.c

world.o: src/world.c src/world.h
	$(CC) $(CFLAGS) -c src/world.c

world_test.o: test/world_test.c src/world.h
	$(CC) $(CFLAGS) -c test/world_test.c

test_main.o: test/main.c test/main.h
	$(CC) $(CFLAGS) -c test/main.c -o test_main.o
