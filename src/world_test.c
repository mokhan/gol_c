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

void test_world_create_should_create_all_cells(){
  World *world = world_create(1, 1);
  assert(false == world->cells[0].alive);
}

void any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population() {
  /*{ 'x', ' ', ' ' },*/
  /*{ ' ', ' ', ' ' },*/
  /*{ ' ', ' ', ' ' },*/
  World *world = world_create(3, 3);
  world->cells[0].alive = false;

  world_evolve(world);
  assert(false == world->cells[0].alive);
  assert(false == world->cells[8].alive);
}

int main()
{
  run_test(test_world_create);
  run_test(test_world_create_should_create_all_cells);
  run_test(any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population);
  printf("\nOK\n");
  return 0;
}
