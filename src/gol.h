static const char ALIVE='x';
static const char DEAD=' ';

extern int WIDTH;
extern int HEIGHT;
extern int NUMBER_OF_CELLS;

int living_neighbours_for(char* world, int index);
char* evolve(char* world);
void display(char* world);
