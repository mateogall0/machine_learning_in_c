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

float random_normal();
void print_matrix(matrix mat);
matrix create_random_normal_matrix();

#endif