#include "neuron.h"

int main()
{
    // Create a neuron with the desired number of input features
    int nx = 784;
    int m = 12665;
    neuron n = create_neuron(nx);

    matrix X_train = matLoadTxt("X_train");
    matrix Y_train = matLoadTxt("Y_train");
    matrix X_dev = matLoadTxt("X_dev");
    matrix Y_dev = matLoadTxt("Y_dev");
    /*
    printf("W: %i, %i\n", n.W.shape[0], n.W.shape[1]);
    printf("X: %i, %i\n", X.shape[0], X.shape[1]);
    printf("Y: %i, %i\n", Y.shape[0], Y.shape[1]);


    train(&n, X, Y, 1000, 0.4, 1, 100);
    puts("\n=========================\n");
    */
    return 0;
}
