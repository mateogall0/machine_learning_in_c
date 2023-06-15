#include "neuron.h"


int main()
{
    neuron n = create_neuron(10);

    print_neuron(n);
    delete_neuron(n);
    return 0;
}