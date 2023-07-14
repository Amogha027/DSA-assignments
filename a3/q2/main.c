#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define N 1000001
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
typedef long long ll;

int main()
{
    ll n, t;
    scanf("%lld %lld", &n, &t);

    while (t--)
    {
        ll pos, k = 4;
        char ch, s[N];
        scanf("%lld %s", &pos, s);

        while (1)
        {
            if (pos % k == (k / 4))
                break;
            else if (pos % k == 3 * (k / 4))
                break;
            k *= 2;
        }

        int i = 0;
        while (1)
        {
            ch = s[i];

            if (ch == 'L')
            {
                if (k != 4)
                {
                    pos = pos - (k / 8);
                    k = k / 2;
                }
            }
            else if (ch == 'R')
            {
                if (k != 4)
                {
                    pos = pos + (k / 8);
                    k = k / 2;
                }
            }
            else if (ch == 'U')
            {
                if (k <= (n + 1))
                {
                    if (pos % k == (k / 4))
                        pos = pos + (k / 4);
                    else
                        pos = pos - (k / 4);
                    k = k * 2;
                }
            }
            else
                break;
            i++;
        }

        printf("%lld\n", pos);
    }

    return 0;
}