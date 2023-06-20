#include "neuron.h"

double random_normal()
{
    double loc = 0.0, scale = 1.0;
	double u1, u2, v1, v2, s;
    do {
        u1 = ((double)rand() / RAND_MAX) * 2 - 1;
        u2 = ((double)rand() / RAND_MAX) * 2 - 1;
        s = u1 * u1 + u2 * u2;
    } while (s >= 1 || s == 0);

    v1 = sqrt(-2 * log(s) / s) * u1;
    v2 = sqrt(-2 * log(s) / s) * u2;

    return loc + scale * v1;
}

void print_matrix(matrix mat)
{
    int i, j;

    for (i = 0; i < mat.shape[0]; i++)
    {
        putchar('[');
        for (j = 0; j < mat.shape[1]; j++)
        {
            printf("%.8lf", mat.mat[i][j]);
            if (j + 1 < mat.shape[1])
                putchar(',');
                putchar(' ');
        }
        putchar(']');
        putchar('\n');
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
    if (mat.shape[0] != 0) free(mat.mat);
    free(mat.shape);
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

matrix dot(matrix mat1, matrix mat2)
{
    matrix result;

    // Check if the matrices can be multiplied
    if (mat1.shape[1] != mat2.shape[0]) {
        fprintf(stderr, "Error: incompatible matrix dimensions for multiplication\n");
        result.mat = NULL;
        result.shape = NULL;
        exit(1);
    }

    // Allocate memory for the result matrix
    result.shape = malloc(sizeof(int) * 2);
    result.shape[0] = mat1.shape[0];
    result.shape[1] = mat2.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (int i = 0; i < result.shape[0]; i++) {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
    }

    // Perform matrix multiplication
    for (int i = 0; i < mat1.shape[0]; i++) {
        for (int j = 0; j < mat2.shape[1]; j++) {
            double sum = 0.0;
            for (int k = 0; k < mat1.shape[1]; k++) {
                sum += mat1.mat[i][k] * mat2.mat[k][j];
            }
            result.mat[i][j] = sum;
        }
    }

    return result;
}

double sum(matrix mat)
{
    double sum = 0.0;

    for (int i = 0; i < mat.shape[0]; i++) {
        for (int j = 0; j < mat.shape[1]; j++) {
            sum += mat.mat[i][j];
        }
    }

    return sum;
}

matrix whereMoreThanPointFive(matrix mat)
{
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (int i = 0; i < result.shape[0]; i++) {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (int j = 0; j < result.shape[1]; j++)
        {
            if (mat.mat[i][j] >= 0.5)
                result.mat[i][j] = 1;
            else
                result.mat[i][j] = 0;
        }
    }

    return result;
}

matrix matLog(matrix mat)
{
    int i, j;
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (i = 0; i < result.shape[0]; i++)
    {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (j = 0; j < result.shape[1]; j++)
            result.mat[i][j] = log(mat.mat[i][j]);
    }
    return result;
}

matrix matAdd(matrix mat, double n)
{
    int i, j;
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (i = 0; i < result.shape[0]; i++)
    {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (j = 0; j < result.shape[1]; j++)
            result.mat[i][j] = mat.mat[i][j] + n;
    }
    return result;
}

matrix matSub(matrix mat, double n)
{
    int i, j;
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (i = 0; i < result.shape[0]; i++)
    {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (j = 0; j < result.shape[1]; j++)
            result.mat[i][j] = mat.mat[i][j] - n;
    }
    return result;
}

matrix matSubLeft(double n, matrix mat)
{
    int i, j;
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (i = 0; i < result.shape[0]; i++)
    {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (j = 0; j < result.shape[1]; j++)
            result.mat[i][j] = n - mat.mat[i][j];
    }
    return result;
}

matrix matMul(matrix mat, double n)
{
    int i, j;
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (i = 0; i < result.shape[0]; i++)
    {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (j = 0; j < result.shape[1]; j++)
            result.mat[i][j] = mat.mat[i][j] * n;
    }
    return result;
}

matrix matDiv(matrix mat, double n)
{
    int i, j;
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (i = 0; i < result.shape[0]; i++)
    {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (j = 0; j < result.shape[1]; j++)
            result.mat[i][j] = mat.mat[i][j] / n;
    }
    return result;
}

matrix matDivLeft(double n, matrix mat)
{
    int i, j;
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (i = 0; i < result.shape[0]; i++)
    {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (j = 0; j < result.shape[1]; j++)
            result.mat[i][j] = n / mat.mat[i][j];
    }
    return result;
}

matrix matExp(matrix mat)
{
    int i, j;
    matrix result;

    result.shape = malloc(sizeof(mat.shape));
    result.shape[0] = mat.shape[0];
    result.shape[1] = mat.shape[1];

    result.mat = malloc(sizeof(double *) * result.shape[0]);
    for (i = 0; i < result.shape[0]; i++)
    {
        result.mat[i] = malloc(sizeof(double) * result.shape[1]);
        for (j = 0; j < result.shape[1]; j++)
            result.mat[i][j] = exp(mat.mat[i][j]);
    }
    return result;
}

matrix matAddOfMatrices(matrix mat1, matrix mat2)
{
    matrix result;
    int rows = mat1.shape[0];
    int columns = mat1.shape[1];

    // Check if the matrices have compatible shapes
    if (rows != mat2.shape[0] || columns != mat2.shape[1]) {
        printf("Error: Matrices are not compatible for addition.\n");
        result.mat = NULL;
        result.shape = NULL;
        return result;
    }

    // Create a new matrix to store the result
    result.mat = (double **)malloc(rows * sizeof(double *));
    result.shape = (int *)malloc(2 * sizeof(int));
    result.shape[0] = rows;
    result.shape[1] = columns;

    // Perform matrix addition
    for (int i = 0; i < rows; i++) {
        result.mat[i] = (double *)malloc(columns * sizeof(double));
        for (int j = 0; j < columns; j++) {
            result.mat[i][j] = mat1.mat[i][j] + mat2.mat[i][j];
        }
    }

    return result;
}

matrix matMulElementWise(matrix mat1, matrix mat2)
{
    int rows = mat1.shape[0];
    int cols = mat1.shape[1];

    // Create a new matrix to store the result
    matrix result;
    result.shape = malloc(2 * sizeof(int));
    result.shape[0] = rows;
    result.shape[1] = cols;

    // Allocate memory for the result matrix
    result.mat = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        result.mat[i] = malloc(cols * sizeof(double));
    }

    // Perform element-wise multiplication
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.mat[i][j] = mat1.mat[i][j] * mat2.mat[i][j];
        }
    }

    return result;
}

matrix matSubElementWise(matrix mat1, matrix mat2)
{
    int rows = mat1.shape[0];
    int cols = mat1.shape[1];

    matrix result;
    result.shape = (int *)malloc(2 * sizeof(int));
    result.shape[0] = rows;
    result.shape[1] = cols;

    result.mat = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        result.mat[i] = (double *)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++)
        {
            result.mat[i][j] = mat1.mat[i][j] - mat2.mat[i][j];
        }
    }

    return result;
}

matrix duplicateMatrix(matrix original)
{
    // Create a new matrix with the same shape
    matrix duplicate;
    duplicate.shape = (int*)malloc(2 * sizeof(int));
    duplicate.shape[0] = original.shape[0];
    duplicate.shape[1] = original.shape[1];

    // Allocate memory for the matrix data
    duplicate.mat = (double**)malloc(original.shape[0] * sizeof(double*));
    for (int i = 0; i < original.shape[0]; i++) {
        duplicate.mat[i] = (double*)malloc(original.shape[1] * sizeof(double));
    }

    // Copy the values from the original matrix to the duplicate
    for (int i = 0; i < original.shape[0]; i++) {
        for (int j = 0; j < original.shape[1]; j++) {
            duplicate.mat[i][j] = original.mat[i][j];
        }
    }

    return duplicate;
}