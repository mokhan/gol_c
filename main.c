#include <stdio.h>
#include "gol.h"

int main(int argc, char **argv) {
  char world[3][3] = {
    { 'x', 'x', 'x' },
    { 'x', 'x', 'x' },
    { 'x', 'x', 'x' },
  };
  evolve(world);
  print(world);
}
