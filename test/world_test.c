#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void test_world_create() {
  int width = 3;
  int height = 3;
  World *world = world_create(width, height);

  assert(width == world->width);
  assert(height == world->height);
}

void test_world_create_should_create_all_cells(){
  World *world = world_create(1, 1);
  assert(false == world_cell_at(world, 0)->alive);
}

void any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population() {
  /*{ 'x', ' ', ' ' },*/
  /*{ ' ', ' ', ' ' },*/
  /*{ ' ', ' ', ' ' },*/
  World *world = world_create(3, 3);
  cell_change_life(world_cell_at(world, 0), true);

  World *new_world = world_evolve(world);
  assert(false == world_cell_at(new_world, 0)->alive);
  assert(false == world_cell_at(new_world, 8)->alive);
}

void any_live_cell_with_two_live_neighbours_lives_on_to_the_next_generation() {
  /*{ 'x', 'x', 'x' },*/
  /*{ ' ', ' ', ' ' },*/
  /*{ ' ', ' ', ' ' },*/
  World *world = world_create(3, 3);
  cell_change_life(world_cell_at(world, 0), true);
  cell_change_life(world_cell_at(world, 1), true);
  cell_change_life(world_cell_at(world, 2), true);

  World* new_world = world_evolve(world);
  assert(true == world_cell_at(new_world, 1)->alive);
}

void any_live_cell_with_three_live_neighbours_lives_on_to_the_next_generation() {
  /*{ 'x', ' ', 'x' },*/
  /*{ ' ', 'x', ' ' },*/
  /*{ ' ', ' ', ' ' },*/
  World *world = world_create(3, 3);
  cell_change_life(world_cell_at(world, 0), true);
  cell_change_life(world_cell_at(world, 2), true);
  cell_change_life(world_cell_at(world, 4), true);

  World* new_world = world_evolve(world);
  assert(true == world_cell_at(new_world, 1)->alive);
}

void any_live_cell_with_more_than_three_live_neighbours_dies_as_if_by_overcrowding() {
  /*{ ' ', 'x', ' ' },*/
  /*{ 'x', 'x', 'x' },*/
  /*{ ' ', 'x', ' ' },*/
  World *world = world_create(3, 3);
  cell_change_life(world_cell_at(world, 1), true);
  cell_change_life(world_cell_at(world, 3), true);
  cell_change_life(world_cell_at(world, 4), true);
  cell_change_life(world_cell_at(world, 5), true);
  cell_change_life(world_cell_at(world, 7), true);

  assert(5 == world_neighbours(world, 0));
  assert(4 == world_neighbours(world, 1));
  assert(4 == world_neighbours(world, 4));

  World* new_world = world_evolve(world);
  assert(false == world_cell_at(new_world, 4)->alive);
}

void any_dead_cell_with_exactly_three_live_neighbours_becomes_a_live_cell_as_if_by_reproduction(){
  /*{ ' ', 'x', ' ' },*/
  /*{ 'x', ' ', 'x' },*/
  /*{ ' ', ' ', ' ' },*/
  World *world = world_create(3, 3);
  cell_change_life(world_cell_at(world, 1), true);
  cell_change_life(world_cell_at(world, 3), true);
  cell_change_life(world_cell_at(world, 5), true);

  World* new_world = world_evolve(world);
  assert(true == world_cell_at(new_world, 4)->alive);
}

void it_returns_the_correct_number_of_living_neighbors() {
  /*{ 'x', ' ', 'x' },*/
  /*{ ' ', ' ', ' ' },*/
  /*{ 'x', ' ', 'x' },*/
  World *world = world_create(3, 3);
  cell_change_life(world_cell_at(world, 0), true);
  cell_change_life(world_cell_at(world, 2), true);
  cell_change_life(world_cell_at(world, 6), true);
  cell_change_life(world_cell_at(world, 8), true);

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

void world_tests() {
  run_test(test_world_create);
  run_test(test_world_create_should_create_all_cells);
  run_test(any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population);
  run_test(any_live_cell_with_two_live_neighbours_lives_on_to_the_next_generation);
  run_test(any_live_cell_with_three_live_neighbours_lives_on_to_the_next_generation);
  run_test(any_live_cell_with_more_than_three_live_neighbours_dies_as_if_by_overcrowding);
  run_test(any_dead_cell_with_exactly_three_live_neighbours_becomes_a_live_cell_as_if_by_reproduction);
  run_test(it_returns_the_correct_number_of_living_neighbors);
}

