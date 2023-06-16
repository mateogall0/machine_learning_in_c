#include "neuron.h"

int main()
{
    neuron n = create_neuron(784); // 784
    matrix X = create_random_normal_matrix(1, 9);
    print_matrix(X);
    puts("===============================================");
    matrix l = matExp(X);
    print_matrix(l);
    n.A = forward_prop(n, X);
    delete_matrix(l);
    delete_neuron(n);
    return 0;
}