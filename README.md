[![Build Status](https://travis-ci.org/mokhan/gol_c.svg?branch=master)](https://travis-ci.org/mokhan/gol_c)

# The Game of Life

This is my implementation of the game of life written in C.

To run this program you must have gcc and make installed. The default
make task will run the program with a 5x5 world.

```bash
  $ make
```

To customize the size of the world you can export the ROWS and COLUMNS
environment variables.

```bash
  $ ROWS=25 COLUMNS=80 make
```

To run the test suite.

```bash
  $ make test
```
