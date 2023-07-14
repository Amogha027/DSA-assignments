#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

#define N 1000001
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)

struct node
{
    char c;
    int n, l, r, idx;
};

int main()
{
    int n;
    scanf("%d", &n);

    char h[n + 1];
    scanf("%s", h);

    struct node *T = (struct node *)malloc(sizeof(struct node) * n);
    f_(i, 0, n)
    {
        T[i].c = h[i];
        T[i].n = i;
        T[i].idx = T[i].l = T[i].r = -1;
    }

    int k = n - 1, a, b, c;
    f_(i, 0, k)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (c == 1)
            T[a - 1].l = b - 1;
        else
            T[a - 1].r = b - 1;
    }

    char pre[n];
    int var = T[0].n, z = 0;
    Stack *s = create_stack();
    push(s, var);
    while (!Is_empty(s))
    {
        int x = pop(s);
        pre[z] = T[x].c;
        T[x].idx = z;
        z++;

        if (T[x].r != -1)
            push(s, T[T[x].r].n);
        if (T[x].l != -1)
            push(s, T[T[x].l].n);
    }

    char str[N];
    scanf("%s", str);

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int q;
        scanf("%d", &q);

        if (q == 1)
        {
            int x;
            char ch;
            scanf("%d %c", &x, &ch);
            int k = T[x - 1].idx;
            pre[k] = ch;
        }
        else
        {
            int la, ra, node;
            scanf("%d %d %d", &la, &ra, &node);

            int start = T[node - 1].idx, w = ra - la + 1;
            if (strncmp(&str[la - 1], &pre[start], w) == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}