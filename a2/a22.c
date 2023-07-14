#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//#include "deque.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)

typedef struct _dequeue Dequeue;
typedef struct _dequeue *deque;
typedef int Element;
typedef struct Node *ptr;

struct _dequeue
{
    ptr front;
    int num;
    ptr rear;
};

struct Node
{
    Element e;
    int idx;
    ptr left;
    ptr right;
};

deque create_dequeue()
{
    deque d = (deque)malloc(sizeof(deque));
    assert(d != NULL);

    d->front = NULL;
    d->rear = NULL;
    d->num = 0;
    return d;
}

ptr create_node(Element x, int y)
{
    ptr p = (ptr)malloc(sizeof(struct Node));
    assert(p != NULL);
    p->e = x;
    p->idx = y;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void push_back(deque d, Element x, int y)
{
    ptr p = create_node(x, y);
    if (d->num == 0)
    {
        d->front = p;
        d->rear = p;
    }
    else
    {
        ptr temp = d->rear;
        temp->right = p;
        p->left = temp;
        d->rear = p;
    }
    (d->num)++;
}

void push_front(deque d, Element x, int y)
{
    ptr p = create_node(x, y);
    if (d->num == 0)
    {
        d->front = p;
        d->rear = p;
    }
    else
    {
        ptr temp = d->front;
        temp->left = p;
        p->right = temp;
        d->front = p;
    }
    (d->num)++;
}

Element pop_front(deque d)
{
    ptr del = d->front;
    int k = del->e;
    if (d->num == 1)
    {
        d->front = NULL;
        d->rear = NULL;
    }
    else
    {
        ptr p = del->right;
        p->left = NULL;
        d->front = p;
    }
    free(del);
    (d->num)--;

    return k;
}

Element pop_back(deque d)
{
    ptr del = d->rear;
    int k = del->e;
    if (d->num == 1)
    {
        d->front = NULL;
        d->rear = NULL;
    }
    else
    {
        ptr p = del->left;
        p->right = NULL;
        d->rear = p;
    }
    free(del);
    (d->num)--;

    return k;
}

int Is_empty(deque d)
{
    return (d->num == 0);
}

int size(deque d)
{
    return d->num;
}

Element front(deque d)
{
    ptr p = d->front;
    return p->e;
}

Element back(deque d)
{
    ptr p = d->rear;
    return p->e;
}

int idx_front(deque d)
{
    ptr p = d->front;
    return p->idx;
}

void print(deque d)
{
    ptr p = d->front;
    while (p != NULL)
    {
        printf("%d ", p->e);
        p = p->right;
    }
    printf("\n");
}

int main()
{
    int n, m, k, i;
    scanf("%d %d", &n, &m);

    deque d = create_dequeue();
    for (i = 0; i < m; i++)
    {
        scanf("%d", &k);
        while (!Is_empty(d) && k <= back(d))
                pop_back(d);
        push_back(d, k, i);
    }

    int arr[n - m + 1], pos = 0;
    arr[pos] = front(d);
    for (i = m; i < n; i++)
    {
        pos++;
        scanf("%d", &k);

        if (!Is_empty(d) && idx_front(d) <= i - m)
                pop_front(d);

        while (!Is_empty(d) && k <= back(d))
                pop_back(d);
        push_back(d, k, i);
        arr[pos] = front(d);
    }

    f_(j, 0, n - m + 1)
        printf("%d ", arr[j]);
    printf("\n");

    return 0;
}