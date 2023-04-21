#include <stdio.h>
#include <stdlib.h>

void dif() {
    int i;
    i = 0;

    int *n = (int *) malloc(sizeof(int));//  int i;// *n may have random value
    int *m = (int *) calloc(1, sizeof(int));//  int i = 0;// *m must have 0 value
}

void owned_memory_demo() {
    char c; // 1 byte; stack
    int n;  // 4 bytes; stack
    char *cp; // 8 bytes; stack
    int *np;  // 8 bytes; stack
    char *np1 = &c; // 8 bytes for pointer; 1 byte for the reference char; stack

    // 4 bytes of heap; 8 bytes of stack memory
    int *np2 = (int *) malloc(sizeof(n));

    // 40 bytes of stack
    int nums[10];

    // 8 bytes of stack
    int (*numsp)[10];

    numsp = &nums; // 40 + 8 stack

    // 40 bytes of heap; 8 bytes of stack
    numsp = (int (*)[10]) calloc(10, sizeof(int));

    // 80 bytes if stack
    char *(argv[10]);

    // plus 4 bytes of data segment memory
    argv[0] = "123";

    // plus 4 bytes of heap memory
    argv[1] = (char *) malloc(4);

    // 8 bytes stack
    int **mat;
    // plus  80 bytes on heap// what this memory will be used to reference
    mat = (int **) malloc(sizeof(int **) * 10);

    // plus 40 bytes on heaps
    mat[0] = (int *) malloc(sizeof(int) * 10);
}

int add1(int a, int b) { return a + b; };

int sub2(int a, int b) { return a - b; };

int main(int argc, char *argv[]) {
    int nums[2] = {1, 2};
    int (*numsp)[2];
    numsp = &nums;
    printf("%d\n", numsp[0][0]);
    // void (*)()
    numsp = (int (*)[2]) calloc(6, sizeof(int));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d\t", numsp[i][j]);
        }
        printf("\n");
    }
    char *words[10];
    printf("%ld\n", sizeof(words));

    // fs owns 2 function pointer  16 bytes on stack

    int (*fs[2])(int, int) = {add1, sub2};

    printf("%ld\n", sizeof(fs));

    for (int i = 0; i < 2; ++i) {
        printf("2 and 1: %d\n", fs[i](2, 1));
    }

    return 0;
}