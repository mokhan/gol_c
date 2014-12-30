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
  world->cells[0].alive = true;

  World *new_world = world_evolve(world);
  assert(false == new_world->cells[0].alive);
  assert(false == new_world->cells[8].alive);
}

void any_live_cell_with_two_live_neighbours_lives_on_to_the_next_generation() {
  /*{ 'x', 'x', 'x' },*/
  /*{ ' ', ' ', ' ' },*/
  /*{ ' ', ' ', ' ' },*/
  World *world = world_create(3, 3);
  world->cells[0].alive = true;
  world->cells[1].alive = true;
  world->cells[2].alive = true;

  World* new_world = world_evolve(world);
  assert(true == new_world->cells[1].alive);
}

void any_live_cell_with_three_live_neighbours_lives_on_to_the_next_generation() {
  /*{ 'x', ' ', 'x' },*/
  /*{ ' ', 'x', ' ' },*/
  /*{ ' ', ' ', ' ' },*/
  World *world = world_create(3, 3);
  world->cells[0].alive = true;
  world->cells[2].alive = true;
  world->cells[4].alive = true;

  World* new_world = world_evolve(world);
  assert(true == new_world->cells[1].alive);
}

void any_live_cell_with_more_than_three_live_neighbours_dies_as_if_by_overcrowding() {
  /*{ ' ', 'x', ' ' },*/
  /*{ 'x', 'x', 'x' },*/
  /*{ ' ', 'x', ' ' },*/
  World *world = world_create(3, 3);
  world->cells[1].alive = true;
  world->cells[3].alive = true;
  world->cells[4].alive = true;
  world->cells[5].alive = true;
  world->cells[7].alive = true;

  assert(5 == world_neighbours(world, 0));
  assert(4 == world_neighbours(world, 1));
  assert(4 == world_neighbours(world, 4));

  World* new_world = world_evolve(world);
  assert(false == new_world->cells[4].alive);
}

void any_dead_cell_with_exactly_three_live_neighbours_becomes_a_live_cell_as_if_by_reproduction(){
  /*{ ' ', 'x', ' ' },*/
  /*{ 'x', ' ', 'x' },*/
  /*{ ' ', ' ', ' ' },*/
  World *world = world_create(3, 3);
  world->cells[1].alive = true;
  world->cells[3].alive = true;
  world->cells[5].alive = true;

  World* new_world = world_evolve(world);
  assert(true == new_world->cells[4].alive);
}

void it_returns_the_correct_number_of_living_neighbors() {
  /*{ 'x', ' ', 'x' },*/
  /*{ ' ', ' ', ' ' },*/
  /*{ 'x', ' ', 'x' },*/
  World *world = world_create(3, 3);
  world->cells[0].alive = true;
  world->cells[2].alive = true;
  world->cells[6].alive = true;
  world->cells[8].alive = true;

  assert(world_neighbours(world, 0) == 3);
  assert(world_neighbours(world, 1) == 4);
  assert(world_neighbours(world, 2) == 3);
  assert(world_neighbours(world, 3) == 4);
  assert(world_neighbours(world, 4) == 4);
  assert(world_neighbours(world, 5) == 4);
  assert(world_neighbours(world, 6) == 3);
  assert(world_neighbours(world, 7) == 4);
  assert(world_neighbours(world, 8) == 3);
}

int main()
{
  run_test(test_world_create);
  run_test(test_world_create_should_create_all_cells);
  run_test(any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population);
  run_test(any_live_cell_with_two_live_neighbours_lives_on_to_the_next_generation);
  run_test(any_live_cell_with_three_live_neighbours_lives_on_to_the_next_generation);
  run_test(any_live_cell_with_more_than_three_live_neighbours_dies_as_if_by_overcrowding);
  run_test(any_dead_cell_with_exactly_three_live_neighbours_becomes_a_live_cell_as_if_by_reproduction);
  run_test(it_returns_the_correct_number_of_living_neighbors);

  printf("\nOK\n");
  return 0;
}
