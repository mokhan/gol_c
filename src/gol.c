#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "gol.h"

int alive(char value) { return value == ALIVE ? 1 : 0; };

int west_of(int index) { return (index % WIDTH == 0) ?  index + (WIDTH-1) : index - 1; }
int east_of(int index) { return (index % WIDTH == (WIDTH-1)) ? index - (WIDTH-1) : index + 1; }
int north_of(int index) { return (index % WIDTH == index) ? NUMBER_OF_CELLS - WIDTH : index - WIDTH; }
int south_of(int index) { 
  return (index >= (NUMBER_OF_CELLS - WIDTH)) ? index - (NUMBER_OF_CELLS - HEIGHT) : index + WIDTH;
}
int north_west_of(int index) { return west_of(north_of(index)); }
int north_east_of(int index) { return east_of(north_of(index)); }
int south_west_of(int index) { return west_of(south_of(index)); }
int south_east_of(int index) { return east_of(south_of(index)); }

int living_neighbours_for(char* world, int index){
  return alive(world[west_of(index)])
    + alive(world[east_of(index)])
    + alive(world[north_of(index)])
    + alive(world[south_of(index)])
    + alive(world[north_west_of(index)])
    + alive(world[north_east_of(index)])
    + alive(world[south_west_of(index)])
    + alive(world[south_east_of(index)])
    ;
}

char* evolve(char* world) {
  char* new_world = malloc(sizeof(char) * NUMBER_OF_CELLS);
  memset(new_world, 0, sizeof(char) * NUMBER_OF_CELLS);
  for (int i = 0; i < NUMBER_OF_CELLS; i++) {
    int neighbours = living_neighbours_for(world, i);
    if (alive(world[i])) {
      new_world[i] = (neighbours >= 2 && neighbours <= 3) ? ALIVE : DEAD;
    } else {
      new_world[i] = neighbours == 3 ? ALIVE : DEAD;
    }
  }
  return new_world;
}

void display(char* world) {
  for (int i = 0; i < NUMBER_OF_CELLS; i++) {
    if (i % WIDTH == 0) { printf("\n"); }
    printf("%c", world[i]);
  }
  printf("\n");
}
