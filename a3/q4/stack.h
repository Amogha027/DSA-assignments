#ifndef __STACK_H_
#define __STACK_H_

typedef struct _stack Stack;
typedef struct _node Node;
typedef struct _node *ptr;
typedef int Element;

struct _stack{
    unsigned int num;
    ptr top;
};

struct _node{
    Element n;
    ptr next;
    ptr prev;
};

Stack *create_stack();
ptr create_node(Element x);
int size(Stack *s);
int Is_empty(Stack *s);
Element top(Stack *s);
Element pop(Stack *s);
void push(Stack *s, Element x);
void print(Stack *s);

#endif