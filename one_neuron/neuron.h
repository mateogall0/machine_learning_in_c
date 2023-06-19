#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct matrix
{
    double **mat;
    int *shape;
} matrix;

typedef struct neuron
{
    matrix W;
    double b;
    matrix A;
}neuron;

double random_normal();
void print_matrix(matrix mat);
matrix create_random_normal_matrix();
void delete_matrix(matrix mat);
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

neuron create_neuron(int nx);
void print_neuron(neuron n);
void delete_neuron(neuron n);
matrix sigmoid(matrix x);
matrix forward_prop(neuron *n, matrix X);
double cost(neuron *n, matrix Y, matrix A);

#endif
