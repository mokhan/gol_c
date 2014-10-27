
typedef struct {
  int x;
  int y;
  char alive;
} Cell;

typedef struct {
  Cell* cells;
  int number_of_cells;
} World;

int living_neighbours_for(World world, Cell cell);
World evolve(World world);
void print(World world);
World create_world(int height, int width);
