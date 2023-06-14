#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define EULER 2.71828182845904523536

typedef struct matrix
{
    double **mat;
    int *shape;
} matrix;

typedef struct neuron
{
    matrix W;
    float b;
    float A;
}neuron;

double random_normal();
void print_matrix(matrix mat);
matrix create_random_normal_matrix();
void delete_matrix(matrix mat);
double sigmoid(double x);
matrix T(matrix mat);

#endif