//
// Created by haoyu on 11/14/2022.
//

#ifndef CS240_HASH_TABLE_H
#define CS240_HASH_TABLE_H

#define HASH int (*hash)(void *key)

typedef struct hash_table_LP {
    void *keys, *vals;
    int keyType, valType, length, capacity, *index;

    int (*hash)(void *key);
} MapLP;

int hash_int(int n);

int hash_int_p(void *n);

int hash_double(double d);

int hash_string(char *s);

int modular_hash(int val, int M);

MapLP new_MapLP(int keyType, int valType, int length, int capacity, HASH);

// the values of key and val will be copied
// not the reference
void put(MapLP map, void *key, void *val);

void *get(MapLP map, void *key);

MapLP new_MapLP_int(int length);

void print_MapLP_int(MapLP map);

void print_MapLP_string(MapLP map);

#endif //CS240_HASH_TABLE_H
