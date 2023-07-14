#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #include "arr.h"
#include "queue.h"

Queue create_queue(size_t n)
{
	Que Q = (Que)malloc(sizeof(Queue));
	assert(Q != NULL);
	Q->capacity = n;
	Q->arr = (Element *)malloc(sizeof(Element) * n);
	assert(Q->arr != NULL);
	Q->front = 0;
	Q->rear = -1;
	Q->num = 0;
	return Q;
}

int Is_empty(Queue S)
{
	return (S->num == 0);
}

int Is_full(Queue S)
{
	return (s->num == s->capacity);
}

void enque(Que Q, Element e)
{
	if (!Is_full(Q))
	{
		(Q->rear) = (Q->rear + 1) % (Q->capacity);
		Q->arr[Q->rear] = e;
		(Q->num)++;
	}
}

Element deque(Que Q)
{
	if (!Is_empty(Q))
	{
		Element e = Q->arr[Q->front];
		Q->front = (Q->front + 1) % (Q->capacity);
		(Q->num)--;
		return e;
	}
	return -1;
}

Element first_term(Queue Q)
{
	return Q->arr[Q->front];
}

void clear_que(Queue Q)
{
	Q->num = 0;
	Q->front = 0;
	Q->rear = -1;
}

void delete_que(Queue *P)
{
	Que Q = *p;
	free(Q->arr);
	free(Q);
	*P = NULL;
}
