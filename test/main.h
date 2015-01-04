#define run_test(function_name)\
  printf("%s\n", #function_name);\
  function_name();

#include <assert.h>

#include "world.h"

void world_tests();
