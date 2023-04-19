
#include <stdio.h>
#include "stdlib.h"
#include "cs240/utils.h"


void array_pointer_demo() {
    char *strings[3] = {"1", "2", "3"};
    int *nums[3];
}


// memeory leak example
void swap1(int a, int b) {
//    int tmp;//

    int *tmp = malloc(sizeof(int));
    *tmp = a;
    a = b;
    b = *tmp;
    // free(tmp)
}


int main(int argc, char *argv[]) {

    int nuns[10];
//    free(nuns);

    int *nums0 = (int *) malloc(sizeof(int) * 10);
    int *nums1 = (int *) calloc(10, sizeof(int));

    print_int_array(nums0, 10);
    print_int_array(nums1, 10);

    free(nums0);
//    free(nums0); // double free
    free(nums1);
    print_int_array(nums0, 10);

    int *nums3;
    print_int_array(nums3, 10);


    int *nums4 = (int *) malloc(sizeof(int) * 10);

    nums4++;
    printf("\n%p\t%d\n", nums4, nums4[0]);
    nums4--;
//    free(nums4);


    return 0;
}