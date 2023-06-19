#include "neuron.h"

int main()
{
    neuron n = create_neuron(784); // 784
    matrix X = create_random_normal_matrix(784, 1);
    print_neuron(n);
    puts("===============================================");
    matrix l = forward_prop(&n, X);
    puts("===============================================");
    puts("===============================================");
    print_matrix(l);
    delete_matrix(X);
    delete_neuron(n);
    return 0;
}