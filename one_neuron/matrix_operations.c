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

void delete_matrix(matrix *mat)
{
    int i;

    if (mat == NULL || mat->shape == NULL || mat->mat == NULL)
        return;

    if (mat->next != NULL)
        mat->next->prev = mat->prev;
    if (mat->prev != NULL)
        mat->prev->next = mat->next;

    if (*head == mat)
        *head = mat->next;

    for (i = 0; i < mat->shape[0]; i++)
        free(mat->mat[i]);

    if (mat->shape[0] != 0)
        free(mat->mat);

    free(mat->shape);

    free(mat);
}

void add_matrix_to_list(matrix *new_matrix) {
    if (head == NULL)
    {
        head = malloc(sizeof(matrix *));
        *head = NULL;
    }
    new_matrix->next = *head;
    if (new_matrix->next)
        new_matrix->next->prev = new_matrix;
    *head = new_matrix;
}
matrix T(matrix mat)
{
    matrix *transposed = malloc(sizeof(matrix));
    int i, j;

    transposed->shape = malloc(sizeof(int) * 2);
    transposed->shape[0] = mat.shape[1];
    transposed->shape[1] = mat.shape[0];

    transposed->mat = malloc(sizeof(double *) * transposed->shape[0]);
    for (i = 0; i < transposed->shape[0]; i++)
        transposed->mat[i] = malloc(sizeof(double) * transposed->shape[1]);
    for (i = 0; i < transposed->shape[1]; i++)
    {
        for (j = 0; j < transposed->shape[0]; j++)
            transposed->mat[j][i] = mat.mat[i][j];
    }

    add_matrix_to_list(transposed);
    return *transposed;
}

matrix dot(matrix mat1, matrix mat2)
{
    matrix *result = malloc(sizeof(matrix));

    // Check if the matrices can be multiplied
    if (mat1.shape[1] != mat2.shape[0]) {
        fprintf(stderr, "Error: incompatible matrix dimensions for multiplication\n");
        result->mat = NULL;
        result->shape = NULL;
        exit(1);
    }

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat1.shape[0];
    result->shape[1] = mat2.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (int i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
    }

    for (int i = 0; i < mat1.shape[0]; i++) {
        for (int j = 0; j < mat2.shape[1]; j++) {
            double sum = 0.0;
            for (int k = 0; k < mat1.shape[1]; k++) {
                sum += mat1.mat[i][k] * mat2.mat[k][j];
            }
            result->mat[i][j] = sum;
        }
    }
    add_matrix_to_list(result);
    return *result;
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
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double*) * result->shape[0]);
    for (int i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (int j = 0; j < result->shape[1]; j++) {
            if (mat.mat[i][j] >= 0.5)
                result->mat[i][j] = 1;
            else
                result->mat[i][j] = 0;
        }
    }

    add_matrix_to_list(result);
    return (*result);
}

matrix matLog(matrix mat)
{
    int i, j;
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (j = 0; j < result->shape[1]; j++) {
            result->mat[i][j] = log(mat.mat[i][j]);
        }
    }
    add_matrix_to_list(result);
    return (*result);
}

matrix matAdd(matrix mat, double n)
{
    int i, j;
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (j = 0; j < result->shape[1]; j++)
            result->mat[i][j] = mat.mat[i][j] + n;
    }
    add_matrix_to_list(result);
    return *result;
}

matrix matSub(matrix mat, double n)
{
    int i, j;
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (j = 0; j < result->shape[1]; j++)
            result->mat[i][j] = mat.mat[i][j] - n;
    }
    add_matrix_to_list(result);
    return *result;
}

matrix matSubLeft(double n, matrix mat)
{
    int i, j;
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (j = 0; j < result->shape[1]; j++)
            result->mat[i][j] = n - mat.mat[i][j];
    }
    add_matrix_to_list(result);
    return *result;
}

matrix matMul(matrix mat, double n)
{
    int i, j;
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (j = 0; j < result->shape[1]; j++)
            result->mat[i][j] = mat.mat[i][j] * n;
    }
    add_matrix_to_list(result);
    return *result;
}

matrix matDiv(matrix mat, double n)
{
    int i, j;
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (j = 0; j < result->shape[1]; j++)
            result->mat[i][j] = mat.mat[i][j] / n;
    }
    add_matrix_to_list(result);
    return *result;
}

matrix matDivLeft(double n, matrix mat)
{
    int i, j;
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (j = 0; j < result->shape[1]; j++)
            result->mat[i][j] = n / mat.mat[i][j];
    }

    add_matrix_to_list(result);
    return *result;
}

matrix matExp(matrix mat)
{
    int i, j;
    matrix *result = malloc(sizeof(matrix));

    result->shape = malloc(sizeof(int) * 2);
    result->shape[0] = mat.shape[0];
    result->shape[1] = mat.shape[1];

    result->mat = malloc(sizeof(double *) * result->shape[0]);
    for (i = 0; i < result->shape[0]; i++) {
        result->mat[i] = malloc(sizeof(double) * result->shape[1]);
        for (j = 0; j < result->shape[1]; j++)
            result->mat[i][j] = exp(mat.mat[i][j]);
    }

    add_matrix_to_list(result);
    return *result;
}

matrix matAddOfMatrices(matrix mat1, matrix mat2)
{
    matrix *result = malloc(sizeof(matrix));
    int rows = mat1.shape[0];
    int columns = mat1.shape[1];

    // Check if the matrices have compatible shapes
    if (rows != mat2.shape[0] || columns != mat2.shape[1]) {
        printf("Error: Matrices are not compatible for addition.\n");
        result->mat = NULL;
        result->shape = NULL;
        return *result;
    }

    // Create a new matrix to store the result
    result->mat = (double **)malloc(rows * sizeof(double *));
    result->shape = (int *)malloc(2 * sizeof(int));
    result->shape[0] = rows;
    result->shape[1] = columns;

    // Perform matrix addition
    for (int i = 0; i < rows; i++) {
        result->mat[i] = (double *)malloc(columns * sizeof(double));
        for (int j = 0; j < columns; j++) {
            result->mat[i][j] = mat1.mat[i][j] + mat2.mat[i][j];
        }
    }

    add_matrix_to_list(result);
    return *result;
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
    matrix *result = malloc(sizeof(matrix));
    int rows = mat1.shape[0];
    int cols = mat1.shape[1];

    // Create a new matrix to store the result
    result->shape = malloc(2 * sizeof(int));
    result->shape[0] = rows;
    result->shape[1] = cols;

    // Allocate memory for the result matrix
    result->mat = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        result->mat[i] = malloc(cols * sizeof(double));
    }

    // Perform element-wise multiplication
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result->mat[i][j] = mat1.mat[i][j] * mat2.mat[i][j];
        }
    }

    add_matrix_to_list(result);
    return *result;
}

matrix matIsEqualElementWise(matrix mat1, matrix mat2)
{
    matrix *result = malloc(sizeof(matrix));
    result->shape = (int *)malloc(2 * sizeof(int));
    result->shape[0] = mat1.shape[0];
    result->shape[1] = mat1.shape[1];

    result->mat = (double **)malloc(result->shape[0] * sizeof(double *));
    for (int i = 0; i < result->shape[0]; i++)
    {
        result->mat[i] = (double *)malloc(result->shape[1] * sizeof(double));
        for (int j = 0; j < result->shape[1]; j++)
        {
            result->mat[i][j] = mat1.mat[i][j] == mat2.mat[i][j] ? 1.0 : 0.0;
        }
    }

    add_matrix_to_list(result);
    return *result;
}

matrix matLoadTxt(char *filename)
{
    matrix parsed;
    FILE *f = NULL;
    size_t sizeBuffer = 4096;
    char *buffer = malloc(sizeBuffer);
    char *token = NULL;
    int shapeFound = 0; // Variable to skip extra operations
    int i, j = 0, k;

    f = fopen(filename, "r");
    if (!f)
    {
        fprintf(stderr, "Error: failed to open file %s", filename);
        exit(1);
    }

    while (getline(&buffer, &sizeBuffer, f) != -1)
    {
        token = strtok(buffer, " #(,)\n");
        if (shapeFound == 0 && !(strcmp(token, "Shape:")))
        {
            parsed.shape = malloc(sizeof(int) * 2);
            for (i = 0; i < 2; i++)
            {
                token = strtok(NULL, " #(,)\n");
                parsed.shape[i] = atoi(token);
            }
            parsed.mat = malloc(sizeof(double *) * parsed.shape[0]);

            // Allocate memory for each row of the matrix
            for (i = 0; i < parsed.shape[0]; i++)
            {
                parsed.mat[i] = malloc(sizeof(double) * parsed.shape[1]);
            }

            shapeFound = 1;
        }
        else
        {
            for (k = 0; k < parsed.shape[1] && token; k++)
            {
                parsed.mat[j][k] = strtod(token, NULL);
                token = strtok(NULL, " #(,)\n");
            }
            j++;
        }
    }
    free(buffer);

    fclose(f);
    printf("%s loaded correctly\n", filename);
    return parsed;
}

void garbage_collector()
{
    matrix *h, *p;
    if (!head) return;
    h = *head;
    while (h)
    {
        p = h;
        h = h->next;
        delete_matrix(p);
    }
    free(head);
}

void print_matrices()
{
    matrix *p;
    if (!head)
    return;
    p = *head;
    while(p)
    {
        print_matrix(*p);
        p = p->next;
    }
}
