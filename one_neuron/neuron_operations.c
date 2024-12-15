#include "neuron.h"

neuron create_neuron(int nx)
{
    neuron n;
    if (nx < 1)
    {
        fprintf(stderr, "Error: nx must be a positive integer\n");
        exit(1);
    }

    n.W = create_random_normal_matrix(1, nx);
    n.b = 0;
    n.A.shape = malloc(sizeof(int) * 2);
    n.A.shape[0] = 0;
    n.A.shape[1] = 0;
    n.A.mat = NULL;

    return n;
}

void print_neuron(neuron n)
{
    puts("Weights: ");
    print_matrix(n.W);
    printf("Bias: %.16lf\n", n.b);
    puts("Anchors: ");
    if (n.A.shape[0] != 0)print_matrix(n.A);
    else puts("0");
}

void delete_neuron(neuron n)
{
}

matrix sigmoid(matrix x)
{
    // sigmoid(x) = 1 / (1 + e^-x)
    return matDivLeft(1, matAdd(matExp(matMul(x, -1)), 1));
}

matrix forward_prop(neuron *n, matrix X)
{
    matrix x = matAdd(dot(n->W, X), n->b);
    return n->A = sigmoid(x);
}

double cost(matrix Y, matrix A)
{
    /*
    To avoid division by zero errors:
    1.0000001 - A instead of 1 - A
    */
    matrix y = matMulElementWise(Y, matLog(A));
    matrix x = matLog(matSubLeft(1.0000001, A));
    x = matMulElementWise(matSubLeft(1, Y), x);
    double c = sum(matAddOfMatrices(y, x));
    return (c * -1) / Y.shape[1];
}

matrix evaluatePrediction(neuron *n, matrix X)
{
    matrix A = forward_prop(n, X);
    return whereMoreThanPointFive(A);
}

double evaluateCost(neuron *n, matrix X, matrix Y)
{
    matrix A = forward_prop(n, X);
    return cost(Y, A);
}

void gradient_descent(neuron *n, matrix X, matrix Y, matrix A, double alpha)
{
    int m = Y.shape[1];

    matrix dZ = matSubElementWise(A, Y);
    matrix dW = matMul(dot(X, T(dZ)), 1.0/m);
    double db = sum(dZ) / m;
    matrix dW_scaled = matMul(dW, alpha);
    
    matrix updated_W = matSubElementWise(n->W, T(dW_scaled));
    n->W = updated_W;
    
    n->b -= alpha * db;
}

void train (neuron *n, matrix X, matrix Y, int iterations, double alpha, int verbose, int step)
{
    int i;
    matrix A;
    double c;

    for (i = 0; i <= iterations; i++)
    {
        A = forward_prop(n, X);
        c = cost(Y, A);
        gradient_descent(n, X, Y, A, alpha);
        if (verbose && (i % step == 0 || i % iterations == 0))
            printf("Cost after %i iterations: %.16lf\n", i, c);
    }
}