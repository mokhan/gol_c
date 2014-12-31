#include "cell.h"

typedef struct {
  int width;
  int height;
  Cell* cells;
} World;

World* world_create(int width, int height);
World* world_random(int width, int height);
World* world_evolve(World* world);
Cell* world_cell_at(World *world, int index);
int world_number_of_cells(World *world);
int world_neighbours(World *world, int index);
void world_print(World *world);
void world_destroy(World *world);
