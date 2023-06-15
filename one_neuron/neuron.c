#include "neuron.h"

int main()
{
    neuron n = create_neuron(784); // 784
    matrix X = create_random_normal_matrix(1, 9);

    print_neuron(n);
    n.A = forward_prop(n, X);
    print_neuron(n);
    delete_neuron(n);
    return 0;
}