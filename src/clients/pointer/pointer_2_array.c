#include <stdio.h>
#include "cs240/utils.h"

void p_2_array_demo() {
    int len = 10;
    int nums[len];

    int (*p_nums)[len] = &nums; // reference type for p_num is int[len]
    int *p = nums; // reference type for p is int
    printf("p_nums : %p\tsizeof pointer %ld\n", p_nums, sizeof(p_nums));
    printf("p : %p\tsizeof pointer %ld\n", p, sizeof(p));
    printf("nums : %p\n", nums);

    // good
    printf("p_nums : %p\tsizeof reference %ld\n", p_nums, sizeof(*p_nums));
    printf("p : %p\tsizeof refernce  %ld\n", p, sizeof(*p));

    printf("p_nums + 1 : %p\tsizeof reference %ld\n", p_nums + 1, sizeof(*p_nums));
    printf("p + 1 : %p\tsizeof refernce  %ld\n", p + 1, sizeof(*p));

}

int rowCompareBy_2nd_reversely(const void *a, const void *b) {
    return (*(int (*)[4]) b)[1] - (*(int (*)[4]) a)[1];
}

int rowCompareBy_2nd(const void *a, const void *b) {
    return (*(int (*)[4]) a)[1] - (*(int (*)[4]) b)[1];
}

void pointer_matrix_demo() {
    int mat[3][4] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    }; // mat can be treated as array of three pointer to int array of [4]
    int (*p_matrix)[4] = mat;
    print_int_matrix(mat, 3, 4);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (p_matrix[i][j] != mat[i][j] || &p_matrix[i][j] != &mat[i][j])
                printf("Oh no");
        }
    }
    printf("All right!\n");

    int hD[1][2][3][4];
    int (*p_hD)[2][3][4] = hD;

    mat[0];
    p_matrix[0];

    print_int_array(mat[0], 4);
    print_int_array(p_matrix[1], 4);

    printf("%p\t%p\n", mat[0], p_matrix[1]); // a0 - 90 = 10  = 16(2)


    // sort a matrix row by the second value of each row reversely
    qsort(mat, 3, sizeof(int) * 4, rowCompareBy_2nd_reversely);
    print_int_matrix(mat, 3, 4);

    printf("compare first row and second row: %d\n", rowCompareBy_2nd_reversely(mat + 0, mat + 1));

}

// sort the index of an array

void demo() {
    int nums[10], len = 10;
    rand_int_array_utils(nums, 10, 20);
    print_int_array(nums, len);
    int mat[10][2];
    for (int i = 0; i < len; ++i) {
        mat[i][0] = i;
        mat[i][1] = nums[i];
    }

    print_int_matrix(mat, 10, 2);
    qsort(mat, len, sizeof(int) * 2, rowCompareBy_2nd);
    print_int_matrix(mat, 10, 2);

}


int main(int argc, char *argv[]) {

//    pointer_matrix_demo();

    demo();

//    int *array_pointer[10];
//    array_pointer[0] = nums;
//    array_pointer[0] = p;
//    for (int i = 0; i < 10; ++i) {
//        printf("array_pointer %d: %p\n", i, array_pointer[i]);
//    }


    return 0;
}