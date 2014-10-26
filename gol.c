#include <stdio.h>

int living_neighbours_for(char world[][3], int x, int y){
  int west = world[y][x-1] == 'x' ? 1 : 0;
  int east = world[y][x+1] == 'x' ? 1 : 0;
  return west + east;
}

void evolve(char world[3][3]) {
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      char* cell = &world[y][x];
      int neighbours = living_neighbours_for(world, x, y);
      printf("%d, %d = '%c'. n: %d\n", x, y, *cell, neighbours);
      world[y][x] = (neighbours >= 2) ? 'x' : ' ';
    }
  }
}

void print(char world[][3]) {
  for (int y = 0; y < 3; y++) {
    printf("%d:", y);
    for (int x = 0; x < 3; x++) {
      printf("%c", world[y][x]);
    }
    printf("\n");
  }
}
