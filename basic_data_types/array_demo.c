//
// Created by AV Services on 9/20/2022.
//
#include <stdio.h>
int main(){
    int a = 10, arr[10];

    for (int i = 0; i < 10; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("%d\t", arr[100]);

    char s[] = {'a', 'b'};
    printf("%s", s);

    int b = (a= 2);
    printf("\nb: %d", b);

    char s1[] ="Hello";
    printf("\n%s", s1);
    printf("\n%d", a = 1);
    printf("\n%d", a != 1);
    printf("\n%d", a == 1);
    printf("\n%d", !2);
    printf("\n%d", !0);

    printf("\n");

    for (int i = 0; i < 3; ++i) {
        switch (i) {
            case 0:
                printf("case: %d\n", i);
            case 1:
                printf("case: %d\n", i);
            default:
                printf("case: the other\n");
        }
    }
    printf("\n%d %d",!0, 10);
    printf("\n%d %d",( !0, 10, 1000));

    for (int i = 0; i < 5; ++i) {
        if (i == 1) continue;
        printf("\n%d",i);
        if (i == 3) break;
    }

}