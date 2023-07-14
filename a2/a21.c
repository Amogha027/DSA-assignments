#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// #include "stack.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)

typedef struct _stack Stack;
typedef struct _node Node;
typedef struct _node *ptr;
typedef long long ll;
typedef ll Element;

struct _stack{
    unsigned int num;
    ptr top;
};

struct _node{
    Element n;
    ptr next;
    ptr prev;
};

Stack *create_stack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    assert(s != NULL);
    s->num = 0;
    s->top = NULL;
    return s;
}

ptr create_node(Element x)
{
    ptr p = (Node *)malloc(sizeof(Node));
    assert(p != NULL);
    p->n = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

ll size(Stack *s)
{
    return s->num;
}

ll Is_empty(Stack *s)
{
    return (s->num == 0);
}

Element top(Stack *s)
{
    ptr p = s->top;
    return p->n;
}

Element pop(Stack *s)
{
    if (s->num > 0)
    {
        ptr p = s->top;
        Element n = p->n;
        if (p->next == NULL)
        {
            s->top = NULL;
        }
        else
        {
            ptr temp = p->next;
            temp->prev = NULL;
            s->top = temp;
        }
        (s->num)--;
        return n;
    }
    return -10;
}

void push(Stack *s, Element x)
{
    ptr p = create_node(x);
    if (s->top != NULL)
    {
        ptr temp = s->top;
        temp->prev = p;
        p->next = temp;
    }
    s->top = p;
    (s->num)++;
}

void print(Stack *s)
{
    printf("%lld\n", size(s));
    Stack *new = create_stack();
    ll k = size(s);
    for (int i = 0; i < k; i++)
    {
        ll t = pop(s);
        push(new, t);
    }

    ptr p = new->top;
    while (p != NULL)
    {
        printf("%lld ", p->n);
        p = p->next;
    }
    printf("\n");
    free(new);
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    ll r = a % b;
    return gcd(b, r);
}

ll lcm(ll a, ll b)
{
    if (a == b)
        return a;
    if (b > a)
    {
        ll k = b;
        while (1)
        {
            if (k % a == 0)
                return k;
            k += b;
        }
    }
    if (b < a)
    {
        ll k = a;
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
    ll n, k, x;
    scanf("%lld", &n);

    Stack *s = create_stack();
    f_(i, 0, n)
    {
        scanf("%lld", &k);
        if (Is_empty(s))
        {
            push(s, k);
        }
        else
        {
            while (size(s) > 0)
            {
                x = pop(s);
                if (gcd(k, x) > 1)
                    k = lcm(x, k);
                else
                {
                    push(s, x);
                    break;
                }
            }
            push(s, k);
        }
    }
    print(s);

    return 0;
}