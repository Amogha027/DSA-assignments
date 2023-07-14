#ifndef __HEAP_H_
#define __HEAP_H_

typedef struct _heap Heap;

struct _heap{
    int size;
    int capacity;
    int *nums;
};

Heap *create_heap(int x);
Heap *build_heap(int *arr, int n);

void insert(Heap *H, int n); // O(logN)
void delete(Heap *H, int idx);

int extract_min(Heap *H);
int heap_size(Heap *H);
int Is_heap_full(Heap *H);
int Is_heap_empty(Heap *H);

void percolate_down_heap(Heap *H, int i);
void percolate_up_heap(Heap *H, int i);

void increase_key(Heap *H, int idx, int x);
void decrease_heap(Heap *H, int idx, int x);

#endif