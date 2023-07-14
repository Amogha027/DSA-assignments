#include <stdio.h>

#define f_(i, j, k) for (int i = j; i < k; i++)

int Is_sorted(int *arr, int j, int n)
{
    f_(i, j + 1, n)
    {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n], count = 0;
    f_(i, 0, n)
        scanf("%d", &a[i]);

    if (Is_sorted(a, 0, n) == 1)
        printf("0\n");
    else
    {
        int x = 0;
        f_(i, 0, n)
        {
            if (a[i] > k)
            {
                int temp = k;
                k = a[i];
                a[i] = temp;
                count++;
            }

            x = Is_sorted(a, i, n);
            if (x == 1)
                break;
        }

        if (Is_sorted(a, 0, n) == 1)
            printf("%d\n", count);
        else
            printf("-1");
    }

    return 0;
}