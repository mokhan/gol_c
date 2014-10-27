#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "gol.h"

int alive(char value) { return value == 'x' ? 1 : 0; };

int west_of(int index) { return (index == 0 || index == 3 || index == 6) ?  index + 2 : index - 1; }
int east_of(int index) { return (index == 2 || index == 5 || index == 8) ? index - 2 : index + 1; }
int north_of(int index) { return (index == 0 || index == 1 || index == 2) ? index + 6 : index - 3; }
int south_of(int index) { return (index == 6 || index == 7 || index == 8) ? index - 6 : index + 3; }
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
  int number_of_cells = 9;
  char new_world[number_of_cells];
  for (int i = 0; i < number_of_cells; i++) {
    int neighbours = living_neighbours_for(world, i);
    if (alive(world[i])) {
      new_world[i] = (neighbours >= 2 && neighbours <= 3) ? 'x' : ' ';
    } else {
      new_world[i] = neighbours == 3 ? 'x' : ' ';
    }
  }
  char* result = new_world;
  return result;
}

void display(char* world) {
  int number_of_cells = 9;
  for (int i = 0; i < number_of_cells; i++) {
    if (i % 3 == 0) { printf("\n"); }
    printf("%c", world[i]);
  }
  printf("\n");
}
