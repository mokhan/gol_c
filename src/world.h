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
int world_neighbours(World* world, int index);
World* world_evolve(World* world);

void world_display(World* world);
