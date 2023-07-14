#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
#include "deque.h"

#define N 1000000000

Search_tree Make_tree_node(ll x)
{
    Search_tree T = (Search_tree)malloc(sizeof(node));
    assert(T != NULL);
    T->e = x;
    T->a = T->b = T->max = T->min = T->check = T->sum = 0;
    T->left = T->right = NULL;
    return T;
}

ll min(ll a, ll b)
{
    if (a <= b)
        return a;
    else
        return b;
}

ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    else
        return b;
}

void fill(Search_tree T)
{
    if (T == NULL)
        return;
    if (T->left == NULL && T->right == NULL)
    {
        T->max = T->min = T->sum = T->e;
        T->a = T->b = T->is_BST = 1;
    }
    else
    {
        fill(T->left);
        fill(T->right);
        if (T->left == NULL)
        {
            T->max = max(T->e, T->right->max);
            T->min = min(T->e, T->right->min);
            T->sum = T->e + T->right->sum;
            if (T->right->a == 1)
            {
                if (T->right->min > T->e && T->right->a == 1)
                    T->a = 1;
            }
            if (T->right->b == 1)
            {
                if (T->right->max < T->e && T->right->b == 1)
                    T->b = 1;
            }
            if (T->a == 1 || T->b == 1)
                T->is_BST = 1;
        }
        else if (T->right == NULL)
        {
            T->max = max(T->e, T->left->max);
            T->min = min(T->e, T->left->min);
            T->sum = T->e + T->left->sum;
            if (T->left->a == 1)
            {
                if (T->left->max < T->e && T->left->a == 1)
                    T->a = 1;
            }
            if (T->left->b == 1)
            {
                if (T->left->min > T->e && T->left->b == 1)
                    T->b = 1;
            }
        }
        else
        {
            ll x = T->left->max, y = T->right->min;
            ll c = T->left->min, d = T->right->max;
            ll a = max(x, d), b = min(y, c);
            T->max = max(T->e, a);
            T->min = min(T->e, b);
            T->sum = T->e + T->left->sum + T->right->sum;
            if (T->left->is_BST == 1 && T->right->is_BST == 1)
            {
                ll one = T->left->a && T->right->a;
                ll two = T->left->b && T->right->b;
                if (one)
                {
                    if (x < T->e && T->e < y)
                        T->a = 1;
                }
                if (two)
                {
                    if (d < T->e && T->e < c)
                        T->b = 1;
                }
            }
        }
        if (T->a == 1 || T->b == 1)
            T->is_BST = 1;
    }
}

Search_tree Find(Search_tree T, ll x)
{
    if (T != NULL)
    {
        if (x == T->e && T->check == 0)
        {
            T->check = 1;
            return T;
        }
        else
        {
            Search_tree temp = NULL;
            if (T->left != NULL)
                temp = Find(T->left, x);
            if (temp == NULL)
            {
                if (T->right != NULL)
                    temp = Find(T->right, x);
            }
            return temp;
        }
    }
    return NULL;
}

ll fun(Search_tree T)
{
    ll ans = N;
    if(T == NULL)
        return ans;
        
    if (T->is_BST)
        ans = T->sum;

    int a = fun(T->left);
    ans = min(ans, a);

    int b = fun(T->right);
    ans = min(ans, b);
    return ans;
}

void In_order_traversal(Search_tree T)
{
    // [left] -- [root] -- [right]
    if (T != NULL)
    {
        In_order_traversal(T->left);
        printf("%lld %lld %lld %lld %lld %lld\n", T->e, T->a, T->b, T->max, T->min, T->is_BST);
        In_order_traversal(T->right);
    }
}