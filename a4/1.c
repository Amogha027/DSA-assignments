#include <stdio.h>
#include <stdlib.h>

#define f_(i, j, k) for (int i = j; i < k; i++)
typedef long long ll;

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int a[n];
        f_(i, 0, n)
            scanf("%d", &a[i]);

        qsort(a, n, sizeof(int), cmpfunc);

        int b[n], p = a[0];
        int z = 0, max = 0, c = 0;
        f_(i, 0, n)
        {
            if (a[i] == p)
                c++;
            else
            {
                if (c > max)
                    max = c;
                b[z++] = c;
                c = 1;
            }
            p = a[i];
        }
        if (c > max)
            max = c;
        b[z++] = c;
        c = 0;

        f_(i, 0, z)
        {
            if (b[i] == max)
                c++;
        }

        if (max == 1)
            printf("%d\n", n);
        else
        {
            int x = n - (c * max);
            int y = max - 1;
            int ans = (x / y) + c - 1;
            printf("%d\n", ans);
        }
    }

    return 0;
}