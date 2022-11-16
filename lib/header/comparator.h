//
// Created by haoyu on 11/1/22.
//

#ifndef CS240_COMPARATOR_H
#define CS240_COMPARATOR_H

int intComparator(const void *const a, const void *const b);

int longComparator(const void *const a, const void *const b);

int *rand_int_array_utils(int *const arr, int l, int max);

void print_int_array_utils(int *const arr, int l);

int stringLenComparator(const void **const a, const void **const b);

#endif //CS240_COMPARATOR_H
