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

    matrix A = evaluatePrediction(&n, X_dev);
    double c = evaluateCost(&n, X_dev, Y_dev);

    printf("Validation accuracy: %lf\n", (sum(matIsEqualElementWise(A, Y_dev)) / Y_dev.shape[1] * 100));
    printf("Validation cost: %lf\n", c);

    delete_matrix(X_train);
    delete_matrix(Y_train);
    delete_matrix(X_dev);
    delete_matrix(Y_dev);

    return 0;
}
