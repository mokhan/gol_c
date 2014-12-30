#include <stdbool.h>

typedef struct {
  bool alive;
} Cell;

typedef struct {
  int width;
  int height;
  Cell* cells;
} World;

World* world_create(int width, int height);
World* world_evolve(World* world);
int world_neighbours(World *world, int index);

void world_display(World* world);
