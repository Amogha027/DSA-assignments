#ifndef __NODE_H_
#define __NODE_H_

typedef struct node Node;
typedef struct node* ptr;

struct node{
	int data; // an integer
	ptr prev; // pointer to the previous node
	ptr next; // pointer to the next node
};

#endif