//
// Created by haoyu on 11/1/22.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "comparator.h"

void stringLenComparator_demo() {
    char *ss[3] = {"abc\n", "ab\n", "a\n"};
    for (int i = 0; i < 3; ++i) {
        printf(ss[i]);
    }
//    ss[0] = ss[1];
    qsort(ss, 3, sizeof(char *), stringLenComparator);
    for (int i = 0; i < 3; ++i) {
        printf(ss[i]);
    }
}

void intComparator_demo() {
    int a = 12, b = 11, l = 10;
    printf("a > b: %d\n", intComparator(&a, &b));
    int arr[l];
    randIntArray(arr, l, 100);
    print_IntArray(arr, l);
    qsort(arr, l, sizeof(int), intComparator);
    print_IntArray(arr, l);
}

int main() {
    intComparator_demo();
    stringLenComparator_demo();
    time(NULL);
    printf("Hours since January 1, 1970 = %ld\n", time(NULL) / 3600);
    srand(time(NULL));
    printf("%d\n", rand());
    printf("%d\n", RAND_MAX);

}