#include "neuron.h"

int main()
{
    // Create a neuron with 3 input features (nx = 3)
    neuron n = create_neuron(3);

    // Create sample input matrix (X)
    matrix X;
    X.shape = malloc(sizeof(int) * 2);
    X.shape[0] = 3; // Number of input features
    X.shape[1] = 2; // Number of samples

    X.mat = malloc(sizeof(double *) * X.shape[0]);
    for (int i = 0; i < X.shape[0]; i++) {
        X.mat[i] = malloc(sizeof(double) * X.shape[1]);
    }

    // Assign values to the input matrix
    X.mat[0][0] = 0.1;
    X.mat[1][0] = 0.2;
    X.mat[2][0] = 0.3;

    X.mat[0][1] = 0.4;
    X.mat[1][1] = 0.5;
    X.mat[2][1] = 0.6;

    // Perform forward propagation
    matrix A = forward_prop(&n, X);

    // Create sample target matrix (Y)
    matrix Y;
    Y.shape = malloc(sizeof(int) * 2);
    Y.shape[0] = 1; // Number of output units
    Y.shape[1] = 2; // Number of samples

    Y.mat = malloc(sizeof(double *) * Y.shape[0]);
    for (int i = 0; i < Y.shape[0]; i++) {
        Y.mat[i] = malloc(sizeof(double) * Y.shape[1]);
    }

    // Assign values to the target matrix
    Y.mat[0][0] = 1;
    Y.mat[0][1] = 0;

    // Calculate the cost
    double cost_val = cost(&n, Y, A);

    // Print the neuron and the cost
    printf("Neuron:\n");
    print_neuron(n);
    printf("Cost: %.8lf\n", cost_val);

    // Cleanup
    delete_neuron(n);
    delete_matrix(X);
    delete_matrix(Y);
    delete_matrix(A);

    return 0;
}