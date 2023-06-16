#include "neuron.h"

int main()
{
    neuron n = create_neuron(784); // 784
    matrix X = create_random_normal_matrix(784, 1);
    print_neuron(n);
    puts("===============================================");
    forward_prop(&n, X);
    puts("===============================================");
    print_neuron(n);
    delete_neuron(n);
    return 0;
}