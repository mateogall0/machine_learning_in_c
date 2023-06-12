#include "main.h"


int main()
{
    matrix mat;

    mat.shape = malloc(sizeof(int) * 3);
    mat.shape[0] = 5;
    mat.shape[1] = 3;
    mat.shape[2] = 0;

    mat.mat = malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; i++)
    {
        mat.mat[i] = malloc(sizeof(int) * 3);
    }

    print_matrix(mat);

    return 0;
}