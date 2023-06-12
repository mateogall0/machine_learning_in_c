#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define EULER 2.71828182845904523536

float random_normal();

typedef struct matrix
{
    int **mat;
    int len;
} matrix;


#endif