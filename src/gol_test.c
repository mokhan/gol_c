#include <stdio.h>
#include "miniunit.h"
#include "gol.h"

int tests_run = 0;

static char* test_foo() {
  int foo = 7;
  assert_equal(foo == 7, "error, foo != 7");
  return 0;
}

static char* any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population() {
  printf("TEST: %s\n", __func__);
  char world[3][3] = {
    { 'x', ' ', ' ' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
  };
  char* new_world = evolve(*world);
  printf("%s\n", new_world);
  assert_equal(new_world[0] == ' ', "should die because has 1 living neighbours");
  assert_equal(new_world[8] == ' ', "should die because has 0 living neighbours");
  return 0;
}

static char* any_live_cell_with_two_live_neighbours_lives_on_to_the_next_generation() {
  printf("TEST: %s\n", __func__);
  char world[3][3] = {
    { 'x', 'x', 'x' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
  };
  char* new_world = evolve(*world);
  assert_equal(new_world[1] == 'x', "should live because has 2 live neighbors");
  return 0;
}

static char* any_live_cell_with_three_live_neighbours_lives_on_to_the_next_generation() {
  printf("TEST: %s\n", __func__);
  char world[3][3] = {
    { 'x', ' ', 'x' },
    { ' ', 'x', ' ' },
    { ' ', ' ', ' ' },
  };
  char* new_world = evolve(*world);
  assert_equal(new_world[1] == 'x', "lives because has 3 live neighbors");
  return 0;
}

static char* any_live_cell_with_more_than_three_live_neighbours_dies_as_if_by_overcrowding() {
  printf("TEST: %s\n", __func__);
  char world[3][3] = {
    { ' ', 'x', ' ' },
    { 'x', 'x', 'x' },
    { ' ', 'x', ' ' },
  };
  char* new_world = evolve(*world);
  assert_equal(new_world[4] == ' ', "dies because has 4 neighbors");
  return 0;
}

static char* any_dead_cell_with_exactly_three_live_neighbours_becomes_a_live_cell_as_if_by_reproduction(){
  printf("TEST: %s\n", __func__);
  char world[3][3] = {
    { ' ', 'x', ' ' },
    { 'x', ' ', 'x' },
    { ' ', ' ', ' ' },
  };
  char* new_world = evolve(*world);
  assert_equal(new_world[4] == 'x', "is born because has 3 live neighbors");
  return 0;
}

static char* it_returns_the_correct_number_of_living_neighbors() {
  printf("TEST: %s\n", __func__);
  char world[3][3] = {
    { 'x', ' ', 'x' },
    { ' ', ' ', ' ' },
    { 'x', ' ', 'x' },
  };
  assert_equal(living_neighbours_for(*world, 0) == 3, "0, 0 should return 3");
  assert_equal(living_neighbours_for(*world, 1) == 4, "1, 0 should return 4");
  assert_equal(living_neighbours_for(*world, 2) == 3, "2, 0 should return 3");
  assert_equal(living_neighbours_for(*world, 3) == 4, "0, 1 should return 4");
  assert_equal(living_neighbours_for(*world, 4) == 4, "1, 1 should return 4");
  assert_equal(living_neighbours_for(*world, 5) == 4, "2, 1 should return 4");
  assert_equal(living_neighbours_for(*world, 6) == 3, "0, 2 should return 3");
  assert_equal(living_neighbours_for(*world, 7) == 4, "1, 2 should return 4");
  assert_equal(living_neighbours_for(*world, 8) == 3, "2, 2 should return 3");
  return 0;
}

static char* all_tests() {
  run_test(test_foo);
  run_test(it_returns_the_correct_number_of_living_neighbors);
  run_test(any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population);
  run_test(any_live_cell_with_two_live_neighbours_lives_on_to_the_next_generation);
  run_test(any_live_cell_with_three_live_neighbours_lives_on_to_the_next_generation);
  run_test(any_live_cell_with_more_than_three_live_neighbours_dies_as_if_by_overcrowding);
  run_test(any_dead_cell_with_exactly_three_live_neighbours_becomes_a_live_cell_as_if_by_reproduction);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("FAILED: %s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);
  return result != 0;
}