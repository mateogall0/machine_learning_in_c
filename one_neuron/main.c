#include "main.h"


int main()
{
    matrix mat = create_random_normal_matrix(1, 99);

    print_matrix(mat);
    
    delete_matrix(mat);
    return 0;
}