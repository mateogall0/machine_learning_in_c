#include "neuron.h"

int main()
{
    // Create a neuron with the desired number of input features
    int nx = 3;
    neuron n = create_neuron(nx);

    // Create the input matrix X and target matrix Y
    int m = 8; // Number of training examples
    matrix X = create_random_normal_matrix(nx, m);
    //print_matrix(create_random_normal_matrix(1, m));
    puts("========================");
    matrix Y = whereMoreThanPointFive(create_random_normal_matrix(1, m));
    //print_matrix(Y);
    puts("========================");
    //print_matrix(X);
    puts("========================");

    matrix A = forward_prop(&n, X);
    double c = cost(Y, A);
    // Set the learning rate
    double alpha = 5;

    print_neuron(n);
    puts("=========================");
    // Perform gradient descent
    gradient_descent(&n, X, Y, A, alpha);
    puts("=========================");
    // Print the updated neuron
    print_neuron(n);



    return 0;
}