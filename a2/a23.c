#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//#include "queue.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
#define N 1000000000

typedef struct _queue Que;
typedef struct _node Node;
typedef struct _node *ptr;
typedef long long ll;
typedef ll Element;
typedef ll pos;

struct _queue{
    ll num;
    ptr head;
    ptr rear;
};

struct _node{
    Element e;
    pos idx;
    ptr next;
    ptr prev;
};

Que *create_que()
{
    Que *c = (Que *)malloc(sizeof(Que));
    assert(c != NULL);
    c->num = 0;
    c->head = NULL;
    c->rear = NULL;
    return c;
}

ptr create_node(Element x, pos y)
{
    ptr p = (Node *)malloc(sizeof(Node));
    assert(p != NULL);
    p->e = x;
    p->idx = y;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

ll size(Que *c)
{
    return c->num;
}

ll Is_empty(Que *c)
{
    return (c->num == 0);
}

Element front(Que *c)
{
    ptr p = c->head;
    return p->e;
}

Element deque(Que *c)
{
    ptr p = c->head;
    ll n = p->e;
    if (c->num > 1)
    {
        ptr temp = p->next;
        temp->prev = NULL;
        c->head = temp;
    }
    else
        c->head = NULL;
    free(p);
    (c->num)--;
    return n;
}

void enque(Que *c, ll x, ll y)
{
    ptr p = create_node(x, y);
    if (c->rear == NULL)
        c->head = p;
    else
    {
        ptr temp = c->rear;
        temp->next = p;
        p->prev = temp;
    }
    c->rear = p;
    (c->num)++;
}

void print(Que *c)
{
    ptr p = c->head;
    while (p != NULL)
    {
        printf("%lld ", p->e);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    ll n, k;
    scanf("%lld", &n);

    Que *c = create_que();

    f_(i, 0, n)
    {
        scanf("%lld", &k);
        enque(c, k, i + 1);
    }

    ll sum = 2 * (n - 1);
    while (size(c) > 1)
    {
        int max = 0, min = N;
        ptr curr = c->head;
        ptr mov = curr->next;
        max = mov->e;

        while (1)
        {
            mov = mov->next;
            if (mov == NULL)
                break;
            min = MIN(mov->e, curr->e);
            if (max < min)
                sum += mov->idx - curr->idx + 1;
            max = MAX(max, mov->e);
        }
        k = deque(c);
    }

    printf("%lld\n", sum);
    return 0;
}