//
// Created by haoyu on 9/2/2022.
//

#ifndef CS240_ARRAYLIST_H
#define CS240_ARRAYLIST_H

#include <malloc.h>


typedef struct ArrayListStruct {
    char *arr;
    int length, capacity, type;
} ArrayList;

ArrayList new_arraylist();
void arraylist_append(ArrayList arr, void *val);
void * arraylist_get(int i);
void arraylist_set(int i, void *val);


#endif //CS240_ARRAYLIST_H
