#include "neuron.h"

int main()
{
    // Create a neuron with the desired number of input features
    int nx = 3;
    neuron n = create_neuron(nx);

    matrix m = create_random_normal_matrix(5, 5);
    print_matrix(m);
    puts("==============");
    m = whereMoreThanPointFive(m);
    print_matrix(m);

    return 0;
}
