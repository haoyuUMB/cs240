
#include <stdio.h>

int array_pass(const int arr[]){
    printf("sizeof arr: %u\n", sizeof(arr));
}

int main(){
    int a,arr[3];
    array_pass(arr);
    printf("sizeof arr: %u\n", sizeof(arr));

    printf("%p\n", arr);  // arr's value
    printf("%p\n", &arr); // arr's address

    printf("%p\n", arr + 1);
    printf("%p\n", &arr + 1);

    // though &arr and arr have the same address value,
    // they are pointing to different data types:
    // arr reference to int;
    // &arr reference to int[3]
    // This is pointer arithmetic
    return 0;
}