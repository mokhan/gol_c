#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "world.h"

void clear_screen(){
  system("clear");
}

int from_env(char* env_name, int default_value) {
  char* value = getenv(env_name);
  return (value != NULL) ? atoi(value) : default_value;
}

void world_start(World *world) {
  srand(time(NULL));
  clear_screen();
  printf("%d x %d world\n", world->width, world->height);
  sleep(2);

  World *new_world = world;
  int i = 0;

  while(true) {
    printf("GENERATION: %d\n", i);
    world_print(new_world);
    World *tmp = world_evolve(new_world);
    world_destroy(new_world);
    new_world = tmp;
    sleep(1);
    clear_screen();
    ++i;
  }
}

int main(int argc, char **argv) {
  int width = from_env("WIDTH", 5);
  int height = from_env("HEIGHT", width);

  world_start(world_random(width, height));
  return 0;
}
