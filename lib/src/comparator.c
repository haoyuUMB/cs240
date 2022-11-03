//
// Created by haoyu on 11/1/22.
//

#include <string.h>
#include "comparator.h"

int intComparator(const void *const a, const void *const b) {
    return *(int *) a - *(int *) b;
}

int stringLenComparator(const void **const a, const void **const b) {
    return strlen(*a) - strlen(*b);
}

