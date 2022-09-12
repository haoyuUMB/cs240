//
// Created by haoyu on 9/2/2022.
//

#include <string.h>
#include "headers/ArrayList.h"
const int POINTER_SIZE = sizeof(int*);
ArrayList new_arraylist(int type){
    return (ArrayList) {malloc(4*type), 2, 4, type};
}

void arraylist_append(ArrayList arr, void *val) {
    arr.length++;
    memcpy(arr.arr[arr.length*arr.type], val, arr.type);
}
