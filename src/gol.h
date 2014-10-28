static const char ALIVE='x';
static const char DEAD=' ';

static const int WIDTH=3;
static const int HEIGHT=3;
static const int NUMBER_OF_CELLS=WIDTH*HEIGHT;

int living_neighbours_for(char* world, int index);
char* evolve(char* world);
void display(char* world);
