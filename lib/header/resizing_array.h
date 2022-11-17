//
// Created by haoyu on 11/5/22.
//

#ifndef CS240_RESIZING_ARRAY_H
#define CS240_RESIZING_ARRAY_H

#define COMPARATOR int (*com)(void *const a, void *const b, void *const data)
#define COMPARATOR2 int (*com)(void *const a, void *const b)
#define SORT Array * (*sort)(Array *const arr, COMPARATOR)
#define SORTS Array * (*sorts[])(Array *const arr, COMPARATOR)

typedef struct array_resizing {
    void *data;
    int type, length, capacity;
} Array;

Array new_Array(int type);

Array new_Array_length(int type, int len);

Array *append_array(Array *const arr, void *val);

Array *pop_array(Array *const arr, void *val);

Array rand_Array_int(int len, int range);

void print_Array_int(Array arr);

void print_Array_int_range(Array arr, int lo, int hi);

Array copy_Array(Array arr);

void swap_Array_items(Array *const arr, int i, int j);

int compare_Array_items(Array *const arr, int i, int j, COMPARATOR);

Array *shuffle_array(Array *const arr);

int min_index_Array(Array *const arr, COMPARATOR);

int min_index_Array_range(Array *const arr, int i, int j, COMPARATOR);

Array *selection_sort_Array(Array *const arr, COMPARATOR);

void copy_2Arrays_range(Array *const des, Array *const src, int di, int si, int len);

int compare_2Arrays_items(Array *const des, Array *const src, int i, int j, COMPARATOR);

int is_sorted_Array_range(Array *const arr, int lo, int hi, COMPARATOR);

Array *merge_Array_range(Array *const arr, Array *const aux, int lo, int mid, int hi, COMPARATOR);

Array *mergesort_Array(Array *const arr, int (*com)(void *const a, void *const b, void *const data));

Array *qsort_Array(Array *const arr, COMPARATOR2);


void test_running_time_Array_sorting(SORT, COMPARATOR, int power);

void *index_address_array(Array *const arr, int i);

void print_Array_attributes(Array arr);

void sorting_comparisons_mergesort_qsort(int power);

void sorting_comparisons_selection_mergesort_qsort(int power);

int int_Comparator(void *const a, void *const b, void *data);

int int_Comparator2(void *const a, void *const b);


#endif //CS240_RESIZING_ARRAY_H
