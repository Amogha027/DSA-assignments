#ifndef __QUEUE_H_
#define __QUEUE_H_

typedef struct _queue Que;
typedef struct _node Node;
typedef struct _node *ptr;
typedef int Element;
typedef int pos;

struct _queue{
    int num;
    ptr head;
    ptr rear;
};

struct _node{
    Element e;
    pos idx;
    ptr next;
    ptr prev;
};

Que *create_que();
ptr create_node(Element x, pos y);
int size(Que *c);
int Is_empty(Que *c);
Element front(Que *c);
Element deque(Que *c); // remove from the front
void enque(Que *c, int x, int y); // add at the end
void print(Que *c);

#endif