#ifndef __QUEUE_H_
#define __QUEUE_H_
// #include "arr.h"

typedef struct _queue Queue;
typedef struct Queue* Que;
typedef int Element;

struct _queue{
	size_t capacity;
	int front;
	int rear;
	int num;
	Element *arr;
};

Que create_queue(size_t n);
void enque(Que Q, Element e);
Element deque(Queue Q);
int Is_empty(Que Q);
int Is_full(Que Q);
void print_que(Que Q);
Element first_term(Que Q);
void clear_que(Que Q);
void delete_que(Que *Q);

#endif