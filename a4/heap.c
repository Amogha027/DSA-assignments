#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "heap.h"

// #--------------------MAX HEAP------------------------#

Heap *create_heap(int x)
{
    Heap *H = (Heap *)malloc(sizeof(Heap));
    assert(H != NULL);

    H->nums = (int *)malloc(sizeof(int) * (1 + x));
    assert(H->nums != NULL);

    H->capacity = 1 + x;
    H->size = 0;
    H->nums[0] = -1234;
    return H;
}

int Is_heap_full(Heap *H)
{
    return H->size == H->capacity - 1;
}

int Is_heap_empty(Heap *H)
{
    return H->size == 0;
}

int heap_size(Heap *H)
{
    return H->size;
}

void insert(Heap *H, int n)
{
    int i;
    assert(!Is_heap_full(H));
    for (i = ++H->size; H->nums[i / 2] < n; i /= 2)
        H->nums[i] = H->nums[i / 2];
    H->nums[i] = n;
}

int extract_min(Heap *H)
{
    assert(!Is_heap_empty(H));
    int child, min = H->nums[1];
    int i, last = H->nums[H->size--];
    for (i = 1; 2 * i <= H->size; i = child)
    {
        child = 2 * i;
        if ((child != H->size) && (H->nums[child + 1] > H->nums[child]))
            child++;

        if (last < H->nums[child])
            H->nums[i] = H->nums[child];
        else
            break;
    }

    H->nums[i] = last;
    return min;
}

void percolate_down_heap(Heap *H, int i)
{
    if (H->size < 2 * i)
        return;
    if (H->size > 2 * i)
    {
        int lol = 2 * i;
        if (H->nums[lol] < H->nums[lol + 1])
            lol++;

        if (H->nums[lol] > H->nums[i])
        {
            int temp = H->nums[lol];
            H->nums[lol] = H->nums[i];
            H->nums[i] = temp;
        }
        percolate_down_heap(H, lol);
    }
    else if (H->size == 2 * i)
    {
        if (H->nums[2 * i] > H->nums[i])
        {
            int temp = H->nums[i];
            H->nums[i] = H->nums[2 * i];
            H->nums[2 * i] = temp;
        }
    }
}

void percolate_up_heap(Heap *H, int i)
{
    if (i == 1)
        return;
    int lol = i / 2;
    if (H->nums[lol] > H->nums[i])
    {
        int temp = H->nums[lol];
        H->nums[lol] = H->nums[i];
        H->nums[i] = temp;
        percolate_up_heap(H, lol);
    }
}

Heap *build_heap(int *arr, int n)
{
    int i;
    Heap *H = create_heap(n);
    // memcpy(H->nums, arr, n * sizeof(int));
    for (int i = 0; i < n; i++)
        H->nums[i + 1] = arr[i];
    H->size = n;

    for (i = n / 2; i > 0; i--)
        percolate_down_heap(H, i);

    return H;
}

void increase_key(Heap *H, int idx, int x)
{
    if (idx == 0 || idx > H->size)
        return;

    H->nums[idx] += x;
    percolate_down_heap(H, idx);
}

void decrease_heap(Heap *H, int idx, int x)
{
    if (idx == 0 || idx > H->size)
        return;

    H->nums[idx] -= x;
    percolate_up_heap(H, idx);
}

void delete (Heap *H, int idx)
{
    if (idx == 0 || idx > H->size)
        return;

    int i, child, last = H->nums[H->size--];
    for (i = idx; 2 * i < H->size; i = child)
    {
        child = 2 * i;
        if ((child != H->size) && (H->nums[child + 1] < H->nums[child]))
            child++;

        if (last > H->nums[child])
            H->nums[i] = H->nums[child];
        else
            break;
    }
    H->nums[i] = last;
}