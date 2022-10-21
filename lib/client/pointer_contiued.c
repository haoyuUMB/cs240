#include <malloc.h>

//
// Created by haoyu on 10/20/22.
//
int main() {
    int (*arr)[3] = (int (*)[3]) calloc(2, 3 * sizeof(int));
    printf("%p\n", arr[1]);
    printf("%p\n", arr[0]);
    printf("%d\n", arr[1][0]);
    printf("%d\n", arr[0][0]);
    printf("%ld\n", arr[1] - arr[0]);
    printf("%ld\n", &arr[1] - &arr[0]);
    memset(arr, 'a', 2 * 3 * sizeof(int));
    for (int i = 0; i < 2; i++) {
        printf("\n");
        for (int j = 0; j < 3; j++)
            printf("%d\t", arr[i][j]);
    }
    int arr1[4];
    arr = arr1;
    printf("\n%p\n", arr + 1);
    printf("%p\n", arr1 + 1);
//    pointer to array, the length matters for pointer arithmetic, but the length does not matter for type compatability

}