#ifndef __DEQUE_H_
#define __DEQUE_H_

typedef struct _dequeue Dequeue;
typedef struct _dequeue *deque;
typedef int Element;
typedef struct Node *ptr;

struct _dequeue{
    ptr front;
    int num;
    ptr rear;
};

struct Node{
    Element e;
    int idx;
    ptr left;
    ptr right;
};

deque create_dequeue();
ptr create_node(Element x, int y);
void push_back(deque d, Element x, int y);
void push_front(deque d, Element x, int y);
Element pop_front(deque d);
Element pop_back(deque d);
int Is_empty(deque d);
int size(deque d);
Element front(deque d);
Element back(deque d);
int idx_front(deque d);
void print(deque d);

#endif