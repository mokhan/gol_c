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
  printf("%s\n", __func__);
  char world[3][3] = {
    { 'x', ' ', ' ' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
  };
  evolve(world);
  assert_equal(world[0][1] == ' ', "should die because has 1 living neighbours");
  assert_equal(world[2][2] == ' ', "should die because has 0 living neighbours");
  return 0;
}

static char* any_live_cell_with_two_live_neighbours_lives_on_to_the_next_generation() {
  printf("%s\n", __func__);
  char world[3][3] = {
    { 'x', ' ', 'x' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
  };
  evolve(world);
  assert_equal(world[0][1] == 'x', "should live because has 2 live neighbors");
  return 0;
}

static char* it_returns_the_correct_number_of_living_neighbors() {
  printf("%s\n", __func__);
  char world[3][3] = {
    { 'x', ' ', 'x' },
    { ' ', ' ', ' ' },
    { ' ', ' ', ' ' },
  };
  assert_equal(living_neighbours_for(world, 0, 0) == 0, "should return 0");
  assert_equal(living_neighbours_for(world, 0, 1) == 2, "should return 2");
  assert_equal(living_neighbours_for(world, 0, 2) == 0, "should return 0");
  return 0;
}

static char* any_live_cell_with_three_live_neighbours_lives_on_to_the_next_generation() {
  return 0;
}

static char* all_tests() {
  run_test(test_foo);
  run_test(it_returns_the_correct_number_of_living_neighbors);
  run_test(any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population);
  run_test(any_live_cell_with_two_live_neighbours_lives_on_to_the_next_generation);
  run_test(any_live_cell_with_three_live_neighbours_lives_on_to_the_next_generation);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);
  return result != 0;
}
