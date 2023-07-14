#include "node.h"
#include "my_dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

ptr root = NULL;
ptr end = NULL;

void insert(DLL list, int x)
{
	ptr p = (ptr)malloc(sizeof(Node));
	assert(p != NULL);
	p->data = x;
	if (root == NULL) // when the linked list is empty
	{
		root = p;
		p->prev = NULL;
		end = p;
		p->next = NULL;
	}
	else
	{
		ptr temp = end;
		p->prev = temp;
		temp->next = p;
		end = p;
		p->next = NULL;
	}
}

void insert_at(DLL list, int x, int i)
{
	ptr p = root;
	ptr k = (ptr)malloc(sizeof(Node));
	assert(k != NULL);
	k->data = x;

	if (i == 0) // when the position is 0
	{
		if (root == NULL) // if linked list is empty
		{
			root = k;
			k->prev = NULL;
			end = k;
			k->next = NULL;
		}
		else
		{
			p->prev = k;
			k->next = p;
			k->prev = NULL;
			root = k;
		}
	}
	else
	{
		int n = 1;
		while (n < i)
		{
			p = p->next;
			n++;
		}

		if (p->next == NULL) // insert at end
		{
			p->next = k;
			k->prev = p;
			k->next = NULL;
			end = k;
		}
		else
		{
			ptr temp = p->next;
			p->next = k;
			k->prev = p;
			k->next = temp;
			temp->prev = k;
		}
	}
}

void delete (DLL list, int i)
{
	int k = get_size(list);
	if (i >= k) // out of range
		printf("Invalid Index\n");
	else
	{
		ptr p = root;
		if (i == 0) // when the position is 0
		{
			if (p->next == NULL) // only 1 element in linked list
			{
				root = NULL;
				end = NULL;
			}
			else
			{
				ptr temp = p->next;
				temp->prev = NULL;
				root = temp;
			}
			free(p);
		}
		else
		{
			int n = 1;
			while (n < i)
			{
				p = p->next;
				n++;
			}

			ptr del = p->next;
			if (del->next == NULL) // if last element is deleted
			{
				p->next = NULL;
				end = p;
			}
			else
			{
				ptr temp = del->next;
				p->next = temp;
				temp->prev = p;
			}
			free(del);
		}
	}
}

int find(DLL list, int x)
{
	int i = 0;
	ptr p = root;
	while (p != NULL)
	{
		if (p->data == x)
			return i;
		p = p->next;
		i++;
	}
	return -1;
}

int get_size(DLL list)
{
	int n = 0;
	ptr p = root;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

void prune(DLL list)
{
	int k = 0, n = get_size(list);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			delete (list, i - k);
			k++;
		}
	}
}

void print(DLL list)
{
	ptr p = root;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void print_reverse(DLL list)
{
	ptr p = end;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->prev;
	}
	printf("\n");
}
