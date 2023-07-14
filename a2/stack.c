#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

Stack *create_stack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    assert(s != NULL);
    s->num = 0;
    s->top = NULL;
    return s;
}

ptr create_node(Element x, int y) {
    ptr p = (Node *)malloc(sizeof(Node));
    assert(p != NULL);
    p->n = x;
    p->idx = y;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

int size(Stack *s) {
    return s->num;
}

int Is_empty(Stack *s) {
    return (s->num == 0);
}

Element top(Stack *s) {
    ptr p = s->top;
    return p->n;
}

Element pop(Stack *s) {
    if (s->num > 0) {
        ptr p = s->top;
        int n = p->n;
        if (p->next == NULL)
            s->top = NULL;
        else {
            ptr temp = p->next;
            temp->prev = NULL;
            s->top = temp;
        }
        (s->num)--;
        return n;
    }
    return -10;
}

void push(Stack *s, Element x, int y) {
    ptr p = create_node(x, y);
    if (s->top != NULL) {
        ptr temp = s->top;
        temp->prev = p;
        p->next = temp;
    }
    s->top = p;
    (s->num)++;
}

int idx_top(Stack *s) {
    ptr p = s->top;
    return p->idx;
}

void print(Stack *s) {
    printf("%d\n", size(s));
    Stack *new = create_stack();
    int k = size(s);
    for (int i = 0; i < k; i++) {
        int t = pop(s);
        push(new, t, i);
    }

    ptr p = new->top;
    while (p != NULL) {
        printf("%d ", p->n);
        p = p->next;
    }
    printf("\n");
    free(new);
}