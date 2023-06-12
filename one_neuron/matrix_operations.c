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


void print_matrix(matrix mat)
{
    int i, j;
    for (i = 0; i < mat.shape[0]; i++)
    {
        putchar('[');
        for (j = 0; j < mat.shape[1]; j++)
        {
            printf("%f", mat.mat[i][j]);
            fflush(stdout);
            if (j + 1 < mat.shape[1])
                write(STDOUT_FILENO, ", ", 2);
        }
        putchar(']');
        putchar(10);
    }
}


matrix create_random_normal_matrix(int height, int width)
{
    matrix mat;

    
    mat.shape = malloc(sizeof(int) * 2);
    mat.shape[0] = height;
    mat.shape[1] = width;

    mat.mat = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++)
    {
        mat.mat[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
        {
            mat.mat[i][j] = random_normal();
        }
    }

    return mat;
}

int delete_matrix(matrix mat)
{
    int i;

    for (i = 0; i < mat.shape[0]; i++)
    {
        free(mat.mat[i]);
    }
    free(mat.mat);
    free(mat.shape);
    return (0);
} 
