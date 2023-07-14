#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define f_(i, j, k) for (int i = j; i < k; i++)
typedef long long ll;

typedef struct _heap Heap;
typedef struct _node Node;

struct _node
{
    int sum;
    int l, r;
};

struct _heap
{
    int size;
    int capacity;
    Node *nums;
};

Heap *create_heap(int x)
{
    Heap *H = (Heap *)malloc(sizeof(Heap));
    assert(H != NULL);

    H->nums = (Node *)malloc(sizeof(Node *) * (1 + x));
    assert(H->nums != NULL);

    H->capacity = 1 + x;
    H->size = 0;

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

void insert(Heap *H, int sum, int l, int r)
{
    int i;
    assert(!Is_heap_full(H));
    for (i = ++H->size; H->nums[i / 2].sum > sum; i /= 2)
        H->nums[i] = H->nums[i / 2];
    H->nums[i].sum = sum;
    H->nums[i].l = l;
    H->nums[i].r = r;
}

Node extract_min(Heap *H)
{
    assert(!Is_heap_empty(H));
    int child, i;
    Node min = H->nums[1], last = H->nums[H->size--];
    for (i = 1; 2 * i <= H->size; i = child)
    {
        child = 2 * i;
        if ((child != H->size) && (H->nums[child + 1].sum < H->nums[child].sum))
            child++;

        if (last.sum > H->nums[child].sum)
            H->nums[i] = H->nums[child];
        else
            break;
    }

    H->nums[i] = last;
    return min;
}

void Merge(int *arr, int l, int m, int r)
{
    int i = l, j = m + 1;
    int b[r - l + 1], z = 0;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
            b[z++] = arr[i++];
        if (arr[j] < arr[i])
            b[z++] = arr[j++];
    }

    while (i <= m)
        b[z++] = arr[i++];
    while (j <= r)
        b[z++] = arr[j++];

    z = 0;
    for (int k = l; k <= r; k++)
        arr[k] = b[z++];
}

void mergeSort(int *arr, int l, int r)
{
    if (l == r)
        return;

    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    Merge(arr, l, m, r);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int k;
        scanf("%d", &k);

        int a[k][k];
        f_(i, 0, k)
        {
            f_(j, 0, k)
                scanf("%d", &a[i][j]);
            mergeSort(&a[i][0], 0, k - 1);
        }

        int c[k], d[k], z = 1;
        Heap *H = create_heap(10 * k);
        f_(i, 0, k)
            c[i] = a[0][i];

        while (z < k)
        {
            Node lol;
            int x = 0, y = 0;

            f_(i, 0, k)
                insert(H, c[i] + a[z][0], i, 0);

            f_(i, 0, k)
            {
                lol = extract_min(H);
                d[i] = lol.sum;
                x = lol.l;
                y = lol.r;
                if (y + 1 < k)
                    insert(H, c[x] + a[z][y + 1], x, y + 1);
            }

            f_(i, 0, k)
                c[i] = d[i];

            while (!Is_heap_empty(H))
            {
                lol = extract_min(H);
            }
            z++;
        }

        if (k % 2 == 1)
        {
            f_(i, 0, k)
                printf("%d ", c[i]);
        }
        else
        {
            f_(i, 0, k)
                printf("%d ", d[i]);
        }
        printf("\n");
    }

    return 0;
}