#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "world.h"

int world_number_of_cells(World *world) {
  return world->width * world->height;
}

int west_of(World *world, int index) {
  return (index % world->width == 0) ? index + (world->width-1) : index - 1;
}

int east_of(World *world, int index) {
  return (index % world->width == (world->width-1)) ? index - (world->width-1) : index + 1;
}

int north_of(World *world, int index) {
  return (index % world->width == index) ? world_number_of_cells(world) - world->width : index - world->width;
}

int south_of(World *world, int index) {
  return (index >= (world_number_of_cells(world) - world->width)) ? index - (world_number_of_cells(world) - world->height) : index + world->width;
}

int north_west_of(World *world, int index) {
  return west_of(world, north_of(world, index));
}

int north_east_of(World *world, int index) {
  return east_of(world, north_of(world, index));
}

int south_west_of(World *world, int index) {
  return west_of(world, south_of(world, index));
}

int south_east_of(World *world, int index) {
  return east_of(world, south_of(world, index));
}

Cell world_cell_at(World *world, int index) {
  return world->cells[sizeof(Cell) * index];
}

int world_neighbours(World *world, int index) {
  Cell west_cell = world_cell_at(world, west_of(world, index));
  Cell east_cell = world_cell_at(world, east_of(world, index));
  Cell north_cell = world_cell_at(world, north_of(world, index));
  Cell south_cell = world_cell_at(world, south_of(world, index));
  Cell north_west_cell = world_cell_at(world, north_west_of(world, index));
  Cell north_east_cell = world_cell_at(world, north_east_of(world, index));
  Cell south_west_cell = world_cell_at(world, south_west_of(world, index));
  Cell south_east_cell = world_cell_at(world, south_east_of(world, index));

  return cell_alive(west_cell)
    + cell_alive(east_cell)
    + cell_alive(north_cell)
    + cell_alive(south_cell)
    + cell_alive(north_west_cell)
    + cell_alive(north_east_cell)
    + cell_alive(south_west_cell)
    + cell_alive(south_east_cell);
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
  World *new_world = world_create(world->width, world->height);
  for (int i = 0; i < number_of_cells; i++) {
    int neighbours = world_neighbours(world, i);
    if (world->cells[i*sizeof(Cell)].alive == true) {
      new_world->cells[i].alive = (neighbours >= 2 && neighbours <= 3) ? true : false;
    } else {
      new_world->cells[i].alive = neighbours == 3 ? true : false;
    }
  }
  return new_world;
}
