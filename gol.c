#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "gol.h"

int alive(char value) {
  return value == 'x' ? 1 : 0;
};

int west_of(char* world, int index) {
  if (index == 0 || index == 3 || index == 6) {
    return alive(world[index + 2]);
  }
  return alive(world[index - 1]);
}

int east_of(char* world, int index) {
  if (index == 2 || index == 5 || index == 8) {
    return alive(world[index - 2]);
  }
  return alive(world[index + 1]);
}

int north_of(char* world, int index) {
  if (index == 0 || index == 1 || index == 2) {
    return alive(world[index + 6]);
  }
  return alive(world[index - 3]);
}

int south_of(char* world, int index) {
  if (index == 6 || index == 7 || index == 8) {
    return alive(world[index - 6]);
  }
  return alive(world[index + 3]);
}

int living_neighbours_for(char* world, int index){
  return west_of(world, index) + east_of(world, index) + north_of(world, index) + south_of(world, index);
}

char* evolve(char* world) {
  int number_of_cells = 9;
  char new_world[number_of_cells + 1];
  memset(new_world, ' ', number_of_cells);
  new_world[number_of_cells] = 0;
  for (int i = 0; i < number_of_cells; i++) {
    int neighbours = living_neighbours_for(world, i);
    new_world[i] = (neighbours >= 2 && neighbours <= 3) ? 'x' : ' ';
  }
  return new_world;
}

void print(char* world) {
  int number_of_cells = 9;
  for (int i = 0; i < number_of_cells; i++) {
    char cell = world[i];
    if (i % 3 == 0) { printf("\n---\n"); }
    printf("%c", cell);
  }
  printf("\n---\n");
}
