#include "neuron.h"

int main()
{
    // Create a neuron with the desired number of input features
    neuron n = create_neuron(784);

    matrix X_train = matLoadTxt("X_train");
    matrix Y_train = matLoadTxt("Y_train");
    matrix X_dev = matLoadTxt("X_dev");
    matrix Y_dev = matLoadTxt("Y_dev");

    train(&n, X_train, Y_train, 1000, 0.5, 1, 100);

    return 0;
}
