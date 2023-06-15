#include "main.h"


int main()
{
    matrix mat = create_random_normal_matrix(10, 10);
    matrix mat2 = create_random_normal_matrix(2, 2);

    print_matrix(mat);

    puts("================");
    print_matrix(whereMoreThanPointFive(mat));

    double su = sum(mat);
    printf("%.16lf\n", su);
    delete_matrix(mat);
    delete_matrix(mat2);

    double s = sigmoid(0.5);

    printf("%.16lf\n", s);
    return 0;
}