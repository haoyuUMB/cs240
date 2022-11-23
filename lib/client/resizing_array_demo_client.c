#include "resizing_array.h"
#include "utils.h"

//
// Created by haoyu on 11/14/22.
//


void append_and_pop_demo() {
    Array arr = new_Array(sizeof(int));
    Array *p_arr = &arr;
    print_Array_attributes(arr);
    for (int i = 0; i < 10; ++i) {
        append_array(p_arr, &i);
    }
    print_Array_attributes(arr);
//    print_int_array(arr.data, arr.length);
    int val;
    for (int i = 0; i < 5; ++i) {
        pop_array(p_arr, &val);
    }
    print_Array_attributes(arr);
//    print_int_array(arr.data, arr.length);
}


void append_pop_long_array_demo() {
    Array arr = new_Array(sizeof(long));
    Array *p_arr = &arr;
    print_Array_attributes(arr);
    for (long i = 0; i < 10; ++i) {
        append_array(p_arr, &i);
    }
    print_Array_attributes(arr);
//    print_int_array(arr.data, arr.length);
    long val;
    for (int i = 0; i < 5; ++i) {
        pop_array(p_arr, &val);
    }
    print_Array_attributes(arr);
    print_long_array(arr.data, arr.length);
}


void int_Array_demo() {
    Array arr = rand_Array_int(10, 29);
    print_Array_int(arr);
}


void copy_Array_demo() {
    Array arr = rand_Array_int(10, 20);
    print_Array_int(arr);
    Array copy = copy_Array(arr);
    print_Array_int(copy);
}

void swap_Array_item_demo() {
    Array arr = rand_Array_int(10, 20);
    Array *p_arr = &arr;
    print_Array_int(arr);
    swap_Array_items(p_arr, 0, 1);
    printf("After swapping index 0 and 1:\n");
    print_Array_int(arr);
}

void compare_Array_items_demo() {
    Array arr = rand_Array_int(10, 20);
    Array *p_arr = &arr;
    print_Array_int(arr);
    int *data = arr.data, i;
    printf("data:\t");
    for (i = 0; i < arr.length - 1; ++i) {
        printf("%d  %c\t", data[i],
               (compare_Array_items(p_arr, i, i + 1, int_Comparator) > 0) ? '>' : '<');
    }
    printf("%d\n", data[i]);
}


void shuffle_demo() {
    Array arr = new_Array(sizeof(int));
    Array *p_arr = &arr;
    for (int i = 0; i < 10; ++i) {
        append_array(p_arr, &i);
    }
    print_Array_int(arr);
    shuffle_array(p_arr);
    print_Array_int(arr);
}

void min_index_Array_demo() {
    Array arr = rand_Array_int(10, 20);
    Array *p_arr = &arr;
    print_Array_int(arr);

    int min = min_index_Array(p_arr, int_Comparator);
    int *data = arr.data;
    printf("minimum index and value are: %d and %d\n", min, data[min]);
}

void selection_sort_Array_demo() {
    Array arr = rand_Array_int(10, 20);
    Array *p_arr = &arr;
    print_Array_int(arr);

    selection_sort_Array(p_arr, int_Comparator);
    print_Array_int(arr);
}

void copy_Array_range_demo() {
    Array arr = rand_Array_int(10, 20);
    Array *p_arr = &arr;
    print_Array_int(arr);

    Array arr2 = rand_Array_int(5, 10);
    Array *p_arr2 = &arr2;
    print_Array_int(arr2);

    copy_2Arrays_range(p_arr2, p_arr, 0, 0, 3);
    print_Array_int(arr2);
}

void compare_2Arrays_items_demo() {

    Array arr1 = rand_Array_int(10, 100);
    Array *p_arr1 = &arr1;
    print_Array_int(arr1);

    Array arr2 = rand_Array_int(10, 100);
    Array *p_arr2 = &arr2;
    print_Array_int(arr2);
    printf("comp:\t");
    char flags[] = {'<', '=', '>'};
    for (int i = 0; i < arr1.length; ++i) {
        int j = compare_2Arrays_items(p_arr1, p_arr2, i, i, int_Comparator);
        if (j > 0) j = 1;
        else if (j < 0) j = -1;
        printf("%c\t", flags[j + 1]);
    }

}

void merge_Array_range_demo() {
    Array arr1 = rand_Array_int(10, 100);
    Array aux = rand_Array_int(10, 100);
    Array *p_arr1 = &arr1;
    print_Array_int(arr1);

    for (int i = 0; i < arr1.length - 1; i += 2) {
        merge_Array_range(p_arr1, &aux, i, i + 1, i + 2, int_Comparator);
    }
    print_Array_int(arr1);
}

void merge_sort_demo() {
    Array arr1 = rand_Array_int(100, 100);
    Array *p_arr1 = &arr1;
    print_Array_int(arr1);

    mergesort_Array(p_arr1, int_Comparator);
    print_Array_int(arr1);
}

void qsort_demo() {
    Array arr1 = rand_Array_int(100, 100);
    Array *p_arr1 = &arr1;
    print_Array_int(arr1);

    qsort_Array(p_arr1, int_Comparator2);
    print_Array_int(arr1);
}

void running_time_test_selection_sort_demo() {
    test_running_time_Array_sorting(selection_sort_Array, int_Comparator, 20);
}

void running_time_test_merge_sort_demo() {
    test_running_time_Array_sorting(mergesort_Array, int_Comparator, 30);
}

int main() {
//    append_and_pop_demo();
//    append_pop_long_array_demo();

//    int_Array_demo();
//    copy_Array_demo();
//    swap_Array_item_demo();
//    compare_Array_items_demo();
//    shuffle_demo();

//    min_index_Array_demo();
//    selection_sort_Array_demo();

//    copy_Array_range_demo();
//    compare_2Arrays_items_demo();

//    merge_Array_range_demo();
//    merge_sort_demo();
//    qsort_demo();

//    running_time_test_selection_sort_demo();
//    running_time_test_merge_sort_demo();

//    sorting_comparisons_mergesort_qsort(30);
//    sorting_comparisons_selection_mergesort_qsort(20);

//    SORTS = {selection_sort_Array, mergesort_Array, qsort_Array};

    Array *(*sorts[])(Array *const arr, COMPARATOR) = {selection_sort_Array, mergesort_Array, qsort_Array};
    printf("%p\n%p\n", sorts[0], selection_sort_Array);


//
//    int arr[] = {1, 2};
//    memswap(arr, arr + 1, 4);
//    print_int_array(arr, 2);


}