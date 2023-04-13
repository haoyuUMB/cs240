#include "cs240/range_minimum.h"
#include "stdlib.h"


void new_range_minimum_int(int *num, int len) {

}


int range_minimum_int(Range_Minimum_Int nums_range, int left, int right) {
    int *nums = nums_range.nums, len = nums_range.len;

    if (len == 0) return -1;
    if (len == 1) return 0;
    int m = 1;
    for (; 1 << m < len; m++);

    int (*aux)[m] = (int (*)[m]) nums_range.aux;
    for (int i = 0; i < len; ++i) {

    }
    return 0;
}