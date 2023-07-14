#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

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

int size(Que *c)
{
    return c->num;
}

int Is_empty(Que *c)
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
    int n = p->e;
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

void enque(Que *c, int x, int y)
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
        printf("%d ", p->e);
        p = p->next;
    }
    printf("\n");
}