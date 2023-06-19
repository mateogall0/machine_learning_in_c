#include "neuron.h"

int main()
{
    neuron n = create_neuron(784);

    delete_neuron(n);
    return 0;
}