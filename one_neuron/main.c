#include "main.h"


int main()
{
    matrix mat = create_random_normal_matrix(1, 99);

    print_matrix(mat);
    
    delete_matrix(mat);

    double s = sigmoid(1);

    printf("%lf\n", s);
    return 0;
}