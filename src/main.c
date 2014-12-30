#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "world.h"

void clear_screen(){
  system("clear");
}

int random_life() {
  return rand() % 2 == 0 ? true : false;
}

World* random_world(int width, int height){
  World *world = world_create(width, height);
  int number_of_cells = world_number_of_cells(world);
  for (int i = 0; i < number_of_cells; i++) {
    world_cell_at(world, i)->alive = random_life();
  }
  return world;
}

int from_env(char* env_name, int default_value) {
  char* value = getenv(env_name);
  if(value != NULL) { return atoi(value); }
  return default_value;
}

int main(int argc, char **argv) {
  int width = from_env("WIDTH", 5);
  int height = from_env("HEIGHT", width);

  srand(time(NULL));
  clear_screen();
  printf("%d x %d world\n", width, height);
  sleep(2);

  World *new_world = random_world(width, height);
  int i = 0;

  while(1) {
    printf("GENERATION: %d\n", i);
    world_print(new_world);
    World *tmp = world_evolve(new_world);
    free(new_world);
    new_world = tmp;
    sleep(1);
    clear_screen();
    ++i;
  }
}
