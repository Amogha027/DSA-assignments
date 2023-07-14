#ifndef _DEQUE_H_
#define _DEQuE_H_

typedef struct _dequeue Dequeue;
typedef struct _dequeue *deque;
typedef struct Node *ptr;
typedef long long ll;

struct _dequeue
{
    ptr front;
    ll num;
    ptr rear;
};

struct Node
{
    Search_tree val;
    ptr left;
    ptr right;
};

deque create_dequeue();
ptr create_node(Search_tree T);
void push_back(deque d, Search_tree T);
Search_tree pop_front(deque d);

#endif