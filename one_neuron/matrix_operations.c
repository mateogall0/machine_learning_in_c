#include "main.h"


float random_normal()
{
	static int initialized = 0;
    float u1, u2;

    if (!initialized) {
        srand(time(NULL));  // Initialize the random number generator
        initialized = 1;
    }

    u1 = (float)rand() / RAND_MAX;  // Generate a random number between 0 and 1
    u2 = (float)rand() / RAND_MAX;  // Generate a second random number between 0 and 1

    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);  // Box-Muller transform
}