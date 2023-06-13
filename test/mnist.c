#include "mnist.h"

int main(void)
{
    // call to store mnist in array
    load_mnist();
    create_binary_subset();
    print_binary_subset();
    return 0;
}