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

    return n;
}

void print_neuron(neuron n)
{
    write(STDOUT_FILENO, "Weights: ", 9);
    fflush(stdout);
    print_matrix(n.W);
    printf("Bias: %.16lf\n", n.b);
    write(STDOUT_FILENO, "Anchors: ", 9);
    fflush(stdout);
    if (n.A.shape[0] != 0)print_matrix(n.A);
    else puts("0");
}

void delete_neuron(neuron n)
{
    delete_matrix(n.W);
    delete_matrix(n.A);
}

double sigmoid(double x)
{
    return 1 / (1 + exp(x * -1));
}

matrix forward_prop(neuron n, matrix X)
{
    delete_matrix(n.A);
    n.A = X;
    return X;
}
