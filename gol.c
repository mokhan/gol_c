#include <stdio.h>
#include "miniunit.h"

int tests_run = 0;

static char* test_foo() {
  int foo = 7;
  assert_equal(foo == 7, "error, foo != 7");
  return 0;
}

static char* test_bar() {
  int bar = 5;
  assert_equal(bar == 5, "error, bar != 5");
  return 0;
}

int evolve(int* cell) {
  return 0;
}

static char* any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population() {
  int cells[] = { 0, 0, 0, 1, 1 };
  assert_equal(evolve(&cells[3]) == 0, "should die because has 1 living neighbours");
  assert_equal(evolve(&cells[1]) == 0, "should die because has 0 living neighbours");
  return 0;
}

static char* any_live_cell_with_two_or_three_live_neighbours_lives_on_to_the_next_generation() {
  int cells[] = { 0, 0, 0, 1, 1 };
  /*assert_equal();*/
  return 0;
}

static char* all_tests() {
  run_test(test_foo);
  run_test(test_bar);
  run_test(any_live_cell_with_fewer_than_two_live_neighbours_dies_as_if_caused_by_under_population);
  run_test(any_live_cell_with_two_or_three_live_neighbours_lives_on_to_the_next_generation);
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
