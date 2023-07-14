#include <stdio.h>
#include <stdlib.h>

#define f_(i, j, k) for (int i = j; i < k; i++)
typedef long long ll;

void Merge(ll *arr, int l, int m, int r)
{
    int i = l, j = m + 1, z = 0;
    ll b[r - l + 1];
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

void mergeSort(ll *arr, int l, int r)
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
    ll n, k;
    scanf("%lld %lld", &n, &k);

    ll a[n], b[n], sum = 0, c = 0;
    f_(i, 0, n)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
        b[i] = sum;
    }

    mergeSort(b, 0, n - 2);
    f_(i, 0, k - 1)
        c += b[i];

    printf("%lld\n", k * sum - c);

    return 0;
}