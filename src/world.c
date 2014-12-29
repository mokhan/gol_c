#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "world.h"

Cell* cell_create(int number_of_cells) {
  Cell *cells = malloc(sizeof(Cell) * number_of_cells);
  memset(cells, 0, sizeof(Cell) * number_of_cells);

  for (int i = 0; i < number_of_cells; i++) {
    cells[sizeof(Cell) * i].alive = false;
  }
  return cells;
}

World *world_create(int width, int height) {
  int number_of_cells = width*height;
  World *world = (World *)malloc(sizeof(World));
  memset(world, 0, sizeof(World));

  world->width = width;
  world->height = height;
  world->cells = cell_create(number_of_cells);
  return world;
}
