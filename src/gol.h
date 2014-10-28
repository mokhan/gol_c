static const char ALIVE='x';
static const char DEAD=' ';

int living_neighbours_for(char* world, int index);
char* evolve(char* world);
void display(char* world);
