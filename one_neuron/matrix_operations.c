#include "main.h"


double random_normal()
{
	static int initialized = 0;
    double u1, u2;

    if (!initialized) {
        srand(time(NULL));  // Initialize the random number generator
        initialized = 1;
    }

    u1 = (double)rand() / RAND_MAX;  // Generate a random number between 0 and 1
    u2 = (double)rand() / RAND_MAX;  // Generate a second random number between 0 and 1

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
            printf("%lf", mat.mat[i][j]);
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

    if (height <= 0 || width <= 0)
    {
        fprintf(stderr, "Error: height and width must be > 0\n");
        exit(1);
    }
    
    mat.shape = malloc(sizeof(int) * 2);
    mat.shape[0] = height;
    mat.shape[1] = width;

    mat.mat = malloc(sizeof(double *) * height);
    for (int i = 0; i < height; i++)
    {
        mat.mat[i] = malloc(sizeof(double) * width);
        for (int j = 0; j < width; j++)
            mat.mat[i][j] = random_normal();
    }

    return mat;
}

void delete_matrix(matrix mat)
{
    int i;

    for (i = 0; i < mat.shape[0]; i++)
        free(mat.mat[i]);
    free(mat.mat);
    free(mat.shape);
}


double sigmoid(double x)
{
    return 1 / (1 + exp(x * -1));
}

matrix T(matrix mat)
{
    matrix transposed;
    int i, j;

    transposed.shape = malloc(sizeof(int) * 2);
    transposed.shape[0] = mat.shape[1];
    transposed.shape[1] = mat.shape[0];

    transposed.mat = malloc(sizeof(double *) * transposed.shape[0]);
    for (i = 0; i < transposed.shape[0]; i++)
        transposed.mat[i] = malloc(sizeof(double) * transposed.shape[1]);
    for (i = 0; i < transposed.shape[1]; i++)
    {
        for (j = 0; j < transposed.shape[0]; j++)
            transposed.mat[j][i] = mat.mat[i][j];
    }

    return transposed;
}