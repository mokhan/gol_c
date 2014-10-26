#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

int main(int argc, char **argv) {
  char world[3][3] = {
    { 'x', 'x', 'x' },
    { 'x', 'x', 'x' },
    { 'x', 'x', 'x' },
  };
  system("clear");
  evolve(world);
  print(world);
}
