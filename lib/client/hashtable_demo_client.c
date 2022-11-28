//
// Created by haoyu on 11/28/2022.
//

#include "resizing_array.h"
#include "hash_table.h"
#include "utils.h"


void int_MapLP_demo() {
    int len = 10;
    int nums[len];
    rand_int_array_utils(nums, len, 10000);
    print_int_array_utils(nums, len);

    MapLP map = new_MapLP_int(len);
    for (int i = 0; i < len; ++i) {
        put(map, &nums[i], &nums[i]);
    }

    print_MapLP_int(map);
}

int main() {
    int_MapLP_demo();
}