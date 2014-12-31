#include <stdbool.h>

typedef struct {
  bool alive;
} Cell;

Cell* cell_create(int number_of_cells);
int cell_alive(Cell *cell);
void cell_change_life(Cell *cell, bool alive);
