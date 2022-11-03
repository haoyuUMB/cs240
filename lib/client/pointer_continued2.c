
#include <malloc.h>

void f() {
    long size = 100000000;
    long *arr = calloc(size, sizeof(long));
    long *arr2 = calloc(size, sizeof(long));
//    for (int i = 0; i < size; ++i) {
//        arr[i] = i;
//    }
    free(arr);
    free(arr2);
}

int main() {
    for (int i = 0; i < 200; ++i) {
        f();
    }
}