#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
#include "deque.h"

#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        ll n;
        scanf("%lld", &n);

        ll a[n];
        f_(i, 0, n)
            scanf("%lld", &a[i]);

        deque d = create_dequeue();
        Search_tree T = Make_tree_node(a[0]);
        push_back(d, T);

        ll z = 1;
        while (z < n - 1)
        {
            ll x = a[z], y = a[z + 1];
            Search_tree temp = pop_front(d);

            if (x != 0)
            {
                Search_tree one = Make_tree_node(x);
                temp->left = one;
                push_back(d, one);
            }
            if (y != 0)
            {
                Search_tree two = Make_tree_node(y);
                temp->right = two;
                push_back(d, two);
            }
            z += 2;
        }

        if (n % 2 == 0)
        {
            ll x = a[z];
            Search_tree temp = pop_front(d);

            if (x != 0)
            {
                Search_tree one = Make_tree_node(x);
                temp->left = one;
                push_back(d, one);
            }
        }

        fill(T);
        printf("%lld\n", fun(T));
    }

    return 0;
}