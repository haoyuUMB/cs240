#include <stdio.h>
#include <malloc.h>
#include <string.h>

//
// Created by haoyu on 10/13/22.
//
void f1(int i) {
    printf("i: %d\taddress:%p\n", i, &i);
    if (i == 0) return;
    else f1(i - 1);
}

int main() {
    int a[10] = {1};
    printf("%d\n", *a);
    f1(5);

    int *pInt = malloc(4);
    free(pInt);
    *pInt = 2; // dangling pointer
    // wild pointer
//    int *p2;
//    *p2 = 1;
//    // free changed pointer
//    int *p3 = malloc(sizeof(int));
//    p3++;
//    free(p3);
    char amessage[] = "now is the time"; /* an array */
    char *pmessage = "now is the time"; /* a pointer */
    printf("amessage:%lu\tpmessage:%lu", sizeof(amessage), sizeof(pmessage));
    amessage[0] = 'H';
    printf(amessage);
//    pmessage[0] = 'h';

    char *ptr[3];
    printf("\nptr:%lu", sizeof(ptr));

    ptr[0] = malloc(20);
    printf("\nptr[0]:%p", ptr[0]);
//    ptr[0] = "hello";// this is not initialization of the heap memory but a reassign of char pointer
    printf("\nptr[0]:%p", ptr[0]);

    // for initialization of allocation heap memory
    // 1. for loop
    // 2. memcpy and strcpy
    strcpy(ptr[0], "hello world");
    strncpy(ptr[0], "\nhello again\n", 20);
    printf(ptr[0]);
    printf("len:%d\n", strlen(ptr[0]));
    printf("len:%p\n", strchr(ptr[0], 'h'));
    printf("len:%p\n", strchr(ptr[0], 'w'));
    memset(ptr[0], 0, 10);
    memset(ptr[0], 'a', 10);
    int *arr = (int *) malloc(4 * sizeof(int));
    memset(arr, 0, 4 * sizeof(int));
    int *arr1 = (int *) calloc(4, sizeof(int));


}