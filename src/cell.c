#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cell.h"

Cell* cell_create(int number_of_cells) {
  Cell *cells = malloc(sizeof(Cell) * number_of_cells);
  memset(cells, 0, sizeof(Cell) * number_of_cells);

  for (int i = 0; i < number_of_cells; i++) {
    cells[sizeof(Cell) * i].alive = false;
  }
  return cells;
}

int cell_alive(Cell *cell) {
  return cell->alive ? 1 : 0;
};

void cell_change_life(Cell *cell, bool alive) {
  cell->alive = alive;
}

void cell_print(Cell *cell) {
  printf("%s", cell->alive ? "X" : " ");
}
