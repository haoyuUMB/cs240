//
// Created by haoyu on 11/14/2022.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

int hash_int(int n) {
    return n;
}

int hash_int_p(void *n) {
    return hash_int(*(int *) n);
}

int hash_double(double d) {
    long *lo = &d;
    return (int) ((*lo) ^ ((*lo) >> 32));
}

int hash_string(char *s) {
    int hash;
    for (int i = 0; s[i]; ++i) {
        hash = s[i] + (31 * hash);
    }
    return hash;
}

int modular_hash(int val, int M) {
    return (val & 0x7fffffff) % M;
}

MapLP new_MapLP(int keyType, int valType, int length, int capacity, HASH) {
    void *keys = calloc(capacity, keyType);
    void *vals = calloc(capacity, valType);
    int *index = calloc(capacity, sizeof(int));
    return (MapLP) {keys, vals, keyType, valType, length, length, index, hash};
}


// this is not resizable
void put(MapLP map, void *key, void *val) {
    int i = modular_hash(map.hash(key), map.capacity);
    for (; map.index[i]; ++i) {
        if (!memcmp(map.keys + i * map.keyType, key, map.keyType)) break;
    }
    memcpy(map.keys + i * map.keyType, key, map.keyType);
    memcpy(map.vals + i * map.valType, val, map.valType);
    map.length++;
    map.index[i] = 1;
}

void *get(MapLP map, void *key) {
    int i = modular_hash(map.hash(key), map.length);
    for (; map.index[i]; ++i) {
        if (!memcmp(map.keys + i * map.keyType, key, map.keyType))
            return map.vals + i * map.valType;
    }
    return NULL;
}

MapLP new_MapLP_int(int length) {
    return new_MapLP(sizeof(int), sizeof(int), length, length << 1, hash_int_p);
}


MapLP new_MapLP_string(int length) {
    return new_MapLP(sizeof(char *), sizeof(int), length, length << 1, hash_string);
}


void print_MapLP_int(MapLP map) {
    int *keys = (int *) map.keys, *vals = (int *) map.vals;
    printf("{\n");
    for (int i = 0; i < map.capacity; ++i) {
        if (map.index[i]) printf("\t%d\t:\t%d\n", keys[i], vals[i]);
    }
    printf("}\n");
}

void print_MapLP_string(MapLP map) {
    int *vals = (int *) map.vals;
    char *keys = (int *) map.keys;
    printf("{\n");
    for (int i = 0; i < map.capacity; ++i) {
        if (map.index[i]) printf("\t%s\t:\t%d\n", keys[i], vals[i]);
    }
    printf("}\n");
}