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

int cell_alive(Cell cell) { return cell.alive == true ? 1 : 0; };

int world_number_of_cells(World *world) {
  return world->width * world->height;
}

int west_of(World *world, int index) { return (index % world->width == 0) ?  index + (world->width-1) : index - 1; }
int east_of(World *world, int index) { return (index % world->width == (world->width-1)) ? index - (world->width-1) : index + 1; }
int north_of(World *world, int index) { return (index % world->width == index) ? world_number_of_cells(world) - world->width : index - world->width; }
int south_of(World *world, int index) { return (index >= (world_number_of_cells(world) - world->width)) ? index - (world_number_of_cells(world) - world->height) : index + world->width; }
int north_west_of(World *world, int index) { return west_of(world, north_of(world, index)); }
int north_east_of(World *world, int index) { return east_of(world, north_of(world, index)); }
int south_west_of(World *world, int index) { return west_of(world, south_of(world, index)); }
int south_east_of(World *world, int index) { return east_of(world, south_of(world, index)); }

int world_neighbours(World *world, int index) {
  return cell_alive(world->cells[sizeof(Cell) * west_of(world, index)])
    + cell_alive(world->cells[sizeof(Cell) * east_of(world, index)])
    + cell_alive(world->cells[sizeof(Cell) * north_of(world, index)])
    + cell_alive(world->cells[sizeof(Cell) * south_of(world, index)])
    + cell_alive(world->cells[sizeof(Cell) * north_west_of(world, index)])
    + cell_alive(world->cells[sizeof(Cell) * north_east_of(world, index)])
    + cell_alive(world->cells[sizeof(Cell) * south_west_of(world, index)])
    + cell_alive(world->cells[sizeof(Cell) * south_east_of(world, index)]);
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

World* world_evolve(World *world) {
  int number_of_cells = world_number_of_cells(world);
  for (int i = 0; i < number_of_cells; i++) {
    int neighbours = world_neighbours(world, i);
    printf("%d: %d\n", i, neighbours);
    if (world->cells[i*sizeof(Cell)].alive == true) {
      world->cells[i].alive = (neighbours >= 2 && neighbours <= 3) ? true : false;
    } else {
      world->cells[i].alive = neighbours == 3 ? true : false;
    }
  }
  return world;
}
