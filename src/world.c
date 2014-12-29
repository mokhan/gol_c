#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "world.h"

World *world_create(int width, int height){
  int bytes_for_cells = ((width*height)*sizeof(Cell));
  int bytes_for_world = sizeof(World);
  int bytes_to_allocate = bytes_for_world + bytes_for_cells;
  printf("%d\n", bytes_to_allocate);

  World *world = (World *)malloc(bytes_to_allocate);
  memset(world, 0, bytes_to_allocate);
  world->width = width;
  world->height = height;
  return world;
}
