#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gol.h"

int WIDTH = 5;
int HEIGHT = 5;
int NUMBER_OF_CELLS;

int random_life() {
  return rand() % 2 == 0 ? ALIVE : DEAD;
}

char* random_world(){
  char *world = malloc(sizeof(char) * NUMBER_OF_CELLS);
  for (int i = 0; i < NUMBER_OF_CELLS; i++) {
    world[i] = random_life();
  }
  return world;
}

int from_env(char* env_name, int default_value) {
  char* value = getenv(env_name);
  if(value != NULL) { return atoi(value); }
  return default_value;
}

int main(int argc, char **argv) {
  WIDTH=from_env("WIDTH", 5);
  HEIGHT=from_env("HEIGHT", WIDTH);
  NUMBER_OF_CELLS=WIDTH*HEIGHT;

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
