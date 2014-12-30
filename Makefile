default: src/*.c src/*.h
	rm -fr bin
	mkdir -p bin
	gcc -std=c99 -Wall -o bin/test_game_of_life src/world_test.c src/world.c src/cell.c src/print.c
	./bin/test_game_of_life
