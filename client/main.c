#include <stdio.h>
#include <malloc.h>
#include "headers/Integer.h"
#include "headers/ArrayList.h"
#include "headers/utils.h"
#include "utils_test.h"

char msg[1000];

int main() {
    test_print();

    printf("Hello, World!\n");
    print_integer(new_integer_val(13));

    Integer a = new_integer_val(777);
    Integer *aa = malloc(sizeof(Integer));
    *aa = a;
    print_integer(*aa);
    ArrayList arr = new_arraylist(sizeof(Integer));
//    for (int i = 0; i < 2; i++){
//        arr.arr[0] =  new_integer_val(i+10);
//    }

    return 0;
}
