#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
#define N 1000000000

int get(int a[], int n)
{
    int min = N;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

int main()
{
    int n, m, k;
    scanf("%d %d", &n, &m);

    Stack *c = create_stack();
    Stack *new = create_stack();
    f_(i, 0, n)
    {
        scanf("%d", &k);
        push(c, k);
    }

    int min = N, a[m - 1];
    f_(i, 0, m)
    {
        int k = pop(c);
        if (i > 0)
            a[i - 1] = k;
        if (k < min)
            min = k;
    }

    push(new, min);
    int z = 0, pos = 0;
    while (z < n - m)
    {
        int t = get(a, m - 1);
        int x = pop(c);
        push(new, MIN(t, x));
        z++;
        a[pos] = x;
        pos++;
        if (pos == m - 1)
            pos = 0;
    }

    ptr p = new->top;
    while (p != NULL)
    {
        printf("%d ", p->n);
        p = p->next;
    }
    printf("\n");

    return 0;
}