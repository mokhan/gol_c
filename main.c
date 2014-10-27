#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gol.h"

int main(int argc, char **argv) {
  char world[3][3] = {
    { ' ', ' ', ' ' },
    { 'x', 'x', 'x' },
    { ' ', ' ', ' ' },
  };
  system("clear");
  char* new_world = *world;
  int i = 0;
  while(1) {
    printf("GENERATION: %d\n", i);
    display(new_world);
    new_world = evolve(new_world);
    sleep(1);
    system("clear");
    ++i;
  }
}
