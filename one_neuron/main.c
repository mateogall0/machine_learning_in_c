#include "main.h"


int main()
{
    matrix mat = create_random_normal_matrix(2, 2);
    matrix mat2 = create_random_normal_matrix(2, 2);

    print_matrix(mat);

    matrix tr = T(mat);
    puts("================");
    print_matrix(mat2);

    puts("================");
    print_matrix(dot(mat, mat2));

    double su = sum(mat);
    printf("%.16lf\n", su);
    delete_matrix(mat);
    delete_matrix(mat2);
    delete_matrix(tr);

    double s = sigmoid(0.5);

    printf("%.16lf\n", s);
    return 0;
}