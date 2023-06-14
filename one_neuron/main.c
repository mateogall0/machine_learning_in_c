#include "main.h"


int main()
{
    matrix mat = create_random_normal_matrix(1, 99);

    print_matrix(mat);

    matrix tr = T(mat);
    puts("================");
    print_matrix(tr);

    delete_matrix(mat);
    delete_matrix(tr);

    double s = sigmoid(0.5);

    printf("%.16lf\n", s);
    return 0;
}