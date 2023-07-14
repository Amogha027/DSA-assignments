#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "hash.h"

struct HashTable *init_hash_table(int a, int b, int countBucket)
{
    struct HashTable *T = (struct HashTable *)malloc(sizeof(struct HashTable));
    assert(T != NULL);
    T->a = a;
    T->b = b;
    T->countBucket = countBucket;

    T->buckets = (struct Bucket *)malloc(countBucket * sizeof(struct Bucket));
    assert(T->buckets != NULL);
    for (int i = 0; i < countBucket; i++)
        T->buckets[i].items = NULL;

    return T;
}

// struct HashTable *insert(struct HashTable *T, int key, int *count)
struct HashTable *insert(struct HashTable *T, int key)
{
    int value = hash_value(T, key);
    struct Item *Position = T->buckets[value].items;
    while (Position != NULL)
    {
        // (*count)++;
        if (Position->key == key)
        {
            (Position->frequency)++;
            return T;
        }
        Position = Position->next;
    }

    struct Item *top = T->buckets[value].items;
    struct Item *temp = (struct Item *)malloc(sizeof(struct Item));
    assert(temp != NULL);
    temp->key = key;
    temp->frequency = 1;
    temp->next = top;
    T->buckets[value].items = temp;
    return T;
}

// struct HashTable *delete (struct HashTable *T, int key, int *count)
struct HashTable *delete (struct HashTable *T, int key)
{
    int value = hash_value(T, key);
    struct Item *Position = T->buckets[value].items;
    while (Position != NULL)
    {
        // (*count)++;
        if (Position->key == key)
        {
            if (Position->frequency > 0)
                (Position->frequency)--;
            return T;
        }
        Position = Position->next;
    }
    return T;
}

int hash_value(struct HashTable *T, int key)
{
    int ans = ((T->a) * key) + T->b;
    return (ans % T->countBucket);
}

// bool search(struct HashTable *T, int key, int *count)
bool search(struct HashTable *T, int key)
{
    int value = hash_value(T, key);
    struct Item *temp = T->buckets[value].items;
    while (temp != NULL)
    {
        // (*count)++;
        if (temp->key == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void print_table(struct HashTable *T)
{
    for (int i = 0; i < T->countBucket; i++)
    {
        struct Item *temp = T->buckets[i].items;
        while (temp != NULL)
        {
            if (temp->frequency > 0)
                printf("%d %d   ", temp->key, temp->frequency);
            temp = temp->next;
        }
        printf("\n");
    }
}