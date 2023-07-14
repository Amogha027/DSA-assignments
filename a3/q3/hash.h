#ifndef __HASH_H_
#define __HASH_H_
#include <stdbool.h>

struct Item{
    int key;
    int frequency;
    struct Item *next;
};

struct Bucket{
    struct Item *items;
};

struct HashTable{
    int a, b, countBucket;
    struct Bucket *buckets;
};

struct HashTable *init_hash_table(int a, int b, int countBucket);
struct HashTable *insert(struct HashTable *T, int key);
struct HashTable *delete(struct HashTable *T, int key);

int hash_value(struct HashTable *T, int key);
bool search(struct HashTable *T, int key);
void print_table(struct HashTable *T);

#endif