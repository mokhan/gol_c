CFLAGS=-Wall -g

default: src/*.c src/*.h
	rm -fr bin
	mkdir -p bin
	gcc -std=c99 -o bin/game_of_life src/main.c src/world.c src/cell.c
	./bin/game_of_life

clean:
	rm -fr bin

test: src/*.c src/*.h
	rm -fr bin
	mkdir -p bin
	gcc -std=c99 -o bin/test_game_of_life src/world_test.c src/world.c src/cell.c
	./bin/test_game_of_life
