
#include "cs240/utils.h"

int int_Compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int int_array_Compare(const void *a, const void *b) {
    int (*pa)[2] = a, (*pb)[2] = b;
    return pa[0][1] - pb[0][1];
}

int main(int argc, char *argv[]) {
    int len = 10, max = 20;
    int nums[len];
    rand_int_array_utils(nums, len, max);

    print_int_array(nums, len);
    qsort(nums, len, sizeof(int), int_Compare);
    print_int_array(nums, len);

    int m = 4, n = 2;
    int mat[m][n];
    rand_int_matrix_utils((int **) mat, m, n, 30);
    print_int_matrix((int **) mat, m, n);
    qsort(mat, m, sizeof(int) * n, int_array_Compare);
    print_int_matrix((int **) mat, m, n);

    return 0;
}