#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "queue.h"
// noooooooooooo

#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    int r = a % b;
    return gcd(b, r);
}

int lcm(int a, int b)
{
    if (a == b)
        return a;
    if (b > a)
    {
        int k = b;
        while (1)
        {
            if (k % a == 0)
                return k;
            k += b;
        }
    }
    if (b < a)
    {
        int k = a;
        while (1)
        {
            if (k % b == 0)
                return k;
            k += a;
        }
    }
}

int main()
{
    int n, k;
    scanf("%d", &n);

    Que *c = create_que();
    f_(i, 0, n)
    {
        scanf("%d", &k);
        enque(c, k, i + 1);
    }

    while (1)
    {
        int before = size(c);

        if (before != 1)
        {
            int a = deque(c);
            if (before == 2)
            {
                int x = deque(c);
                if (gcd(a, x) > 1)
                    enque(c, lcm(a, x), 1);
                else
                {
                    enque(c, a, 1);
                    enque(c, x, 2);
                }
            }
            else
            {
                int z = 1, pos = 1;
                while (z < before)
                {
                    int x = deque(c);
                    if (gcd(a, x) > 1)
                    {
                        enque(c, lcm(a, x), pos);
                        z += 2;
                        if (z <= before)
                            a = deque(c);
                        pos++;
                    }
                    else
                    {
                        enque(c, a, pos);
                        pos++;
                        a = x;
                        z++;
                    }
                }
                enque(c, a, pos);
                // print(c);
            }
        }
        int after = size(c);

        if (before == after)
        {
            print(c);
            break;
        }
    }

    //print(c);

    return 0;
}