#ifndef __DLL_H_
#define __DLL_H_
#include "node.h"

typedef struct my_dll DLL;

struct my_dll{
    ptr root;
    ptr end;
};

void insert(DLL list, int x);            // insert x at the end
void insert_at(DLL list, int x, int i); // insert x at position i
void delete(DLL list, int i);          // delete at position i
int find(DLL list, int x);            // return the position of first occurence of x, else return -1
void prune(DLL list);                // delete all odd indexes
void print(DLL list);               // print the linked list from index 0
void print_reverse(DLL list);      // print the linked list in reverse order
int get_size(DLL list);           // return the no of elements in the linked list

#endif