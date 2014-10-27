#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

int main(int argc, char **argv) {
  World world = create_world(3, 3);
  system("clear");
  /*for (int i = 0; i < 5; i++) {*/
    /*evolve(world);*/
    print(world);
  /*}*/
}
