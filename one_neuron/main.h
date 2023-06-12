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
    float **mat;
    int *shape;
} matrix;

typedef struct neuron
{
    matrix W;
    float b;
    float A;
}neuron;

float random_normal();
void print_matrix(matrix mat);
matrix create_random_normal_matrix();
int delete_matrix(matrix mat);

#endif