#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

// Declaration of the Matrix structure
typedef struct matrix
{
    double **mat;
    int *shape;
    struct matrix *next;
    struct matrix *prev;
} matrix;

// Declaration of the Neuron structure
typedef struct neuron
{
    matrix W;
    double b;
    matrix A;
}neuron;

// Matrix functions
double random_normal();
void print_matrix(matrix mat);
matrix create_random_normal_matrix();
void delete_matrix(matrix *mat);
matrix T(matrix mat);
matrix dot(matrix mat1, matrix mat2);
double sum(matrix a);
matrix whereMoreThanPointFive(matrix mat);
matrix matLog(matrix mat);
matrix matAdd(matrix mat, double n);
matrix matSub(matrix mat, double n);
matrix matSubLeft(double n, matrix mat);
matrix matMul(matrix mat, double n);
matrix matDiv(matrix mat, double n);
matrix matDivLeft(double n, matrix mat);
matrix matExp(matrix mat);
matrix matAddOfMatrices(matrix mat1, matrix mat2);
matrix matMulElementWise(matrix mat1, matrix mat2);
matrix matSubElementWise(matrix mat1, matrix mat2);
matrix matIsEqualElementWise(matrix mat1, matrix mat2);
void print_matrices();
void add_matrix_to_list(matrix *new_matrix);

// Matrix parser for the dataset
matrix matLoadTxt(char *filename);

// Garbage collector
void garbage_collector();

// Neuron functions
neuron create_neuron(int nx);
void print_neuron(neuron n);
void delete_neuron(neuron n);
matrix sigmoid(matrix x);
matrix forward_prop(neuron *n, matrix X);
double cost(matrix Y, matrix A);
matrix evaluatePrediction(neuron *n, matrix X);
double evaluateCost(neuron *n, matrix X, matrix Y);
void gradient_descent(neuron *n, matrix X, matrix Y, matrix A, double alpha);
void train (neuron *n, matrix X, matrix Y, int iterations, double alpha, int verbose, int step);


extern matrix **head;

#endif
