#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "world.h"

#define run_test(function_name)\
  printf("%s\n", #function_name);\
  function_name();

void test_world_create() {
  int width = 3;
  int height = 3;
  World *world = world_create(width, height);

  assert(width == world->width);
  assert(height == world->height);
}

int main()
{
  run_test(test_world_create);
  printf("\nOK\n");
  return 0;
}
