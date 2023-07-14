#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #include "heap.h"

#define f_(i, j, k) for (int i = j; i < k; i++)
typedef long long ll;
typedef struct _heap Heap;

struct _heap{
    int size;
    int capacity;
    ll *nums;
};

Heap *create_heap(int x)
{
    Heap *H = (Heap *)malloc(sizeof(Heap));
    assert(H != NULL);

    H->nums = (ll *)malloc(sizeof(ll) * (1 + x));
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
    for (i = ++H->size; H->nums[i / 2] > n; i /= 2)
        H->nums[i] = H->nums[i / 2];
    H->nums[i] = n;
}

ll extract_min(Heap *H)
{
    assert(!Is_heap_empty(H));
    int child;
    ll min = H->nums[1];
    int i, last = H->nums[H->size--];
    for (i = 1; 2 * i <= H->size; i = child)
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
    return min;
}

void percolate_down_heap(Heap *H, int i)
{
    if (H->size < 2 * i)
        return;
    if (H->size > 2 * i)
    {
        int lol = 2 * i;
        if (H->nums[lol] > H->nums[lol + 1])
            lol++;

        if (H->nums[lol] < H->nums[i])
        {
            ll temp = H->nums[lol];
            H->nums[lol] = H->nums[i];
            H->nums[i] = temp;
        }
        percolate_down_heap(H, lol);
    }
    else if (H->size == 2 * i)
    {
        if (H->nums[2 * i] < H->nums[i])
        {
            ll temp = H->nums[i];
            H->nums[i] = H->nums[2 * i];
            H->nums[2 * i] = temp;
        }
    }
}

Heap *build_heap(ll *arr, ll n)
{
    int i;
    Heap *H = create_heap(n);
    // memcpy(H->nums, arr, n * sizeof(int));
    for (i = 0; i < n; i++)
        H->nums[i + 1] = arr[i];
    H->size = n;

    for (i = n / 2; i > 0; i--)
        percolate_down_heap(H, i);

    return H;
}

int main()
{
    ll k, n;
    scanf("%lld %lld", &k, &n);

    ll a[n], ans = 0;
    f_(i, 0, n)
        scanf("%lld", &a[i]);

    Heap *H = build_heap(a, n);
    while (H->size > 1)
    {
        ll x = extract_min(H);
        ll y = extract_min(H);
        ans += x + y;
        insert(H, x + y);
    }

    printf("%lld\n", ans);
    return 0;
}