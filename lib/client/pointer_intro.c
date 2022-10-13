#include <stdio.h>
#include <malloc.h>

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


}