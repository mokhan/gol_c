#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gol.h"

int random_life() {
  return rand() % 2 == 0 ? ALIVE : DEAD;
}

char* random_world(){
  char *world = malloc(sizeof(char) * 9);
  for (int i = 0; i < 9; i++) {
    world[i] = random_life();
  }
  return world;
}

int main(int argc, char **argv) {
  srand(time(NULL));
  system("clear");

  char* new_world = random_world();
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
