//
// Created by haoyu on 4/7/2023.
//

#ifndef CS240_RANGE_MINIMUM_H
#define CS240_RANGE_MINIMUM_H
typedef struct {
    int *nums, len, *aux
} Range_Minimum_Int;
int range_minimum_int(Range_Minimum_Int nums, int i, int j) ;

#endif //CS240_RANGE_MINIMUM_H