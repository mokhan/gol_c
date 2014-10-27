#include <stdio.h>
#include <stdlib.h>
#include "gol.h"
#include <time.h>

Cell find_cell(World world, int x, int y) {
  for (int i = 0; i < world.number_of_cells; i++) {
    Cell cell = world.cells[i];
    if (cell.x == x && cell.y == y) {
      return cell;
    }
  }
  Cell null_cell;
  null_cell.x = -1;
  null_cell.y = -1;
  null_cell.alive = ' ';
  return null_cell;
}

int living_neighbours_for(World world, Cell cell){
  int west = find_cell(world, cell.y, cell.x - 1).alive == 'x' ? 1 : 0;
  int east = find_cell(world, cell.y, cell.x + 1).alive == 'x' ? 1 : 0;
  return west + east;
}

World evolve(World world) {
  for (int i = 0; i < world.number_of_cells; i++) {
    Cell cell = world.cells[i];
    int neighbours = living_neighbours_for(world, cell);
    cell.alive = (neighbours >= 2) ? 'x' : ' ';
  }
  return world;
}

void print(World world) {
  for (int i = 0; i < world.number_of_cells; i++) {
    Cell cell = world.cells[i];
    if (i % 3 == 0) { printf("\n---\n"); }
    printf("%c", cell.alive);
  }
  printf("\n---\n");
}

char random_life() {
  /*srand(time(NULL));*/
  /*return rand() % 7 == 0 ? 'x' : ' ';*/
  return 'x';
}

World create_world(int height, int width){
  World world;
  Cell* cells = (Cell*)malloc(sizeof(Cell) * (height * width));
  int cell_number = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      Cell cell;
      cell.x = x;
      cell.y = y;
      cell.alive = random_life();
      cells[cell_number] = cell;
      ++cell_number;
    }
  }
  world.cells = cells;
  world.number_of_cells = height*width;
  return world;
}
