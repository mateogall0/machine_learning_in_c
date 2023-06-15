#include "neuron.h"


neuron create_neuron(int nx)
{
    neuron n;
    if (nx < 1)
    {
        fprintf(stderr, "Error: nx must be a positive integer\n");
        return n;
    }

    n.W = create_random_normal_matrix(1, nx);
    n.b = 0;
    n.A = 0;

    return n;
}

void print_neuron(neuron n)
{
    write(STDOUT_FILENO, "Weights: ", 9);
    fflush(stdout);
    print_matrix(n.W);
    printf("Bias: %lf\n", n.b);
    printf("Anchor: %lf\n", n.A);
}

void delete_neuron(neuron n)
{
    delete_matrix(n.W);
}