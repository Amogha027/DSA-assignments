#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//#include "stack.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)

typedef struct _stack Stack;
typedef struct _node Node;
typedef struct _node *ptr;
typedef long long ll;
typedef ll Element;

struct _stack
{
    unsigned int num;
    ptr top;
};

struct _node
{
    Element n;
    ll idx;
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

ptr create_node(Element x, ll y)
{
    ptr p = (Node *)malloc(sizeof(Node));
    assert(p != NULL);
    p->n = x;
    p->idx = y;
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
        ll n = p->n;
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

void push(Stack *s, Element x, ll y)
{
    ptr p = create_node(x, y);
    if (s->top != NULL)
    {
        ptr temp = s->top;
        temp->prev = p;
        p->next = temp;
    }
    s->top = p;
    (s->num)++;
}

ll idx_top(Stack *s)
{
    ptr p = s->top;
    return p->idx;
}

void print(Stack *s)
{
    printf("%lld\n", size(s));
    Stack *new = create_stack();
    ll k = size(s);
    for (int i = 0; i < k; i++)
    {
        ll t = pop(s);
        push(new, t, i);
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

int main()
{
    ll n, k;
    scanf("%lld", &n);

    ll sum = 0;
    Stack *s = create_stack();
    f_(i, 0, n)
    {
        scanf("%lld", &k);
        if (i != 0)
        {
            while (size(s) > 0)
            {
                ll x = top(s);
                ll l = idx_top(s);
                sum += i - l + 1;
                if (k > x)
                {
                    pop(s);
                }
                else
                    break;
            }
        }
        push(s, k, i);
    }
    printf("%lld\n", sum);

    return 0;
}