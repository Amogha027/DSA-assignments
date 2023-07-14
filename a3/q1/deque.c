#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
#include "deque.h"

deque create_dequeue()
{
    deque d = (deque)malloc(sizeof(deque));
    assert(d != NULL);

    d->front = NULL;
    d->rear = NULL;
    d->num = 0;
    return d;
}

ptr create_node(Search_tree T)
{
    ptr p = (ptr)malloc(sizeof(struct Node));
    assert(p != NULL);
    p->val = T;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void push_back(deque d, Search_tree T)
{
    ptr p = create_node(T);
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

Search_tree pop_front(deque d)
{
    ptr del = d->front;
    Search_tree k = del->val;
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