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
double sigmoid(double x);
matrix T(matrix mat);
matrix dot(matrix mat1, matrix mat2);
double sum(matrix a);
matrix whereMoreThanPointFive(matrix mat);
matrix matLog(matrix mat);
matrix matAdd(matrix mat, double n);
matrix matSubRight(matrix mat, double n);
matrix matMul(matrix mat, double n);
matrix matDivLeft(double n, matrix mat);
matrix matExp(matrix mat);

neuron create_neuron(int nx);
void print_neuron(neuron n);
void delete_neuron(neuron n);
matrix forward_prop(neuron n, matrix X);

#endif
