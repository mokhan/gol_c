#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gol.h"

int main(int argc, char **argv) {
  char world[3][3] = {
    { ' ', ' ', ' ' },
    { 'x', 'x', 'x' },
    { ' ', ' ', ' ' },
  };
  system("clear");
  for (int i = 0; i < 5; i++) {
    evolve(*world);
    print(*world);
    sleep(1);
    system("clear");
  }
}
