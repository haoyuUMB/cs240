#include <malloc.h>
#include <string.h>

//
// Created by haoyu on 10/20/22.
//

void demo2() {
    int (*mat)[4] = (int (*)[4]) malloc(5 * 4 * sizeof(int));
    int *arr = (int *) mat;
    printf("\n");

    for (int i = 0; i < 20; ++i) {
        arr[i] = i;
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf("\n");
        for (int j = 0; j < 4; ++j) {
            printf("%d\t", mat[i][j]);
        }
    }
    printf("\n");


    printf("\nmat addr:%p\n", mat);
    printf("mat + 1 addr:%p\n", mat + 1);
    printf("*mat addr:%p\n", *mat);
    printf("*mat + 1 addr:%p\n", *mat + 1); // next int (*mat is an int pointer)
    printf("*(mat + 1) addr:%p\n", *(mat + 1)); // next row address (mat is int[4] pointer)
    printf("1st row addr:%d\n", *mat + 1 == *(mat + 1));
    printf("1st row addr:%d\n", mat + 1 == *(mat + 1));
    printf("1st row addr:%d\n", *mat == mat);
}

void demo1() {
    int **mat = malloc(2 * sizeof(int *));
    mat[0] = malloc(4 * sizeof(int));
    mat[1] = malloc(8 * sizeof(int));
    for (int i = 0; i < 2; ++i) {
        printf("\n");
        for (int j = 0; j < (i == 0 ? 4 : 8); ++j) {
            printf("%d\t", mat[i][j]);
        }
    }
}

void demo() {
//    int *arr = malloc(12 * sizeof(int));
    int arr[12];
    for (int i = 0; i < 12; ++i) { arr[i] = i; }
    for (int i = 0; i < 12; ++i) { printf("%d\t", arr[i]); }
    printf("\n");
    int (*mat)[3] = (int (*)[3]) arr;
    for (int i = 0; i < 4; ++i) {
        printf("\n");
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", mat[i][j]);
        }
    }
    arr[1] = 100;
    for (int i = 0; i < 4; ++i) {
        printf("\n");
        for (int j = 0; j < 3; ++j) {
            printf("%d\t", mat[i][j]);
        }
    }
    int (*mat3)[2][3] = (int (*)[2][3]) arr;
    for (int i = 0; i < 2; ++i) {
        printf("\n");
        for (int j = 0; j < 2; ++j) {
            printf("\n");
            for (int k = 0; k < 3; ++k) {
                printf("%d\t", mat3[i][j][k]);
            }
        }
    }
}

int main() {
    int (*arr)[3] = (int (*)[3]) calloc(2, 3 * sizeof(int));


    printf("%p\n", arr[2]);
    printf("%p\n", arr[1]);
    printf("%p\n", arr[0]);
    printf("%p\n", &arr[0]);
    printf("%d\n", arr[1][0]);
    printf("%d\n", arr[0][0]);
//    printf("%ld\n", arr[1] - arr[0]);
//    printf("%ld\n", &arr[1] - &arr[0]);
    memset(arr, 'a', 2 * 3 * sizeof(int));
//    for (int i = 0; i < 2; i++) {
//        printf("\n");
//        for (int j = 0; j < 3; j++)
//            printf("%d\t", arr[i][j]);
//    }
    int arr1[4];
    arr = arr1;
    printf("\n%p\n", arr + 1);
    printf("%p\n", arr1 + 1);
    demo();
    demo1();
    printf("\n%d", 010 + 1);
    printf("\n%d", 0xa1);
    demo2();
//    pointer to array, the length matters for pointer arithmetic, but the length does not matter for type compatability
}