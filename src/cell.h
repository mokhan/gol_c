#include <stdbool.h>

typedef struct {
  bool alive;
} Cell;

Cell* cell_create(int number_of_cells);
int cell_alive(Cell cell);
