#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
// #include "stack.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)

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
    int idx;
    ptr next;
    ptr prev;
};

Stack *create_stack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    assert(s != NULL);
    s->num = 0;
    s->top = NULL;
    return s;
}

ptr create_node(Element x, int y)
{
    ptr p = (Node *)malloc(sizeof(Node));
    assert(p != NULL);
    p->n = x;
    p->idx = y;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

int size(Stack *s)
{
    return s->num;
}

int Is_empty(Stack *s)
{
    return (s->num == 0);
}

Element top(Stack *s)
{
    ptr p = s->top;
    return p->n;
}

Element pop(Stack *s)
{
    if (s->num > 0)
    {
        ptr p = s->top;
        int n = p->n;
        if (p->next == NULL)
        {
            s->top = NULL;
        }
        else
        {
            ptr temp = p->next;
            temp->prev = NULL;
            s->top = temp;
        }
        (s->num)--;
        return n;
    }
    return -10;
}

void push(Stack *s, Element x, int y)
{
    ptr p = create_node(x, y);
    if (s->top != NULL)
    {
        ptr temp = s->top;
        temp->prev = p;
        p->next = temp;
    }
    s->top = p;
    (s->num)++;
}

int idx_top(Stack *s)
{
    ptr p = s->top;
    return p->idx;
}

void print(Stack *s)
{
    printf("%d\n", size(s));
    Stack *new = create_stack();
    int k = size(s);
    for (int i = 0; i < k; i++)
    {
        int t = pop(s);
        push(new, t, i);
    }

    ptr p = new->top;
    while (p != NULL)
    {
        printf("%d ", p->n);
        p = p->next;
    }
    printf("\n");
    free(new);
}

int main()
{
    char ch;
    int n, m, k;
    scanf("%d %d", &n, &m);

    int a[n][m], max = 0;
    f_(i, 0, n)
    {
        f_(j, 0, m)
        {
            scanf(" %c", &ch);
            if (ch == '*')
                k = 0;
            else
                k = 1;

            if (i == 0 || k == 0)
                a[i][j] = k;
            else
                a[i][j] = k + a[i - 1][j];
        }
    }

    f_(i, 0, n)
    {
        int l[m], r[m], z = 0;
        f_(i, 0, m)
        {
            l[i] = -1;
            r[i] = m;
        }

        Stack *s = create_stack();
        f_(j, 0, m)
        {
            while (!Is_empty(s))
            {
                int y = idx_top(s);
                int x = top(s);
                if (x > a[i][j])
                {
                    r[y] = j;
                    pop(s);
                }
                else
                    break;
            }
            push(s, a[i][j], j);
        }

        Stack *c = create_stack();
        f__(j, m - 1, 0)
        {
            // l[j] = -1;
            while (!Is_empty(c))
            {
                int y = idx_top(c);
                int x = top(c);
                if (x > a[i][j])
                {
                    l[y] = j;
                    pop(c);
                }
                else
                    break;
            }
            push(c, a[i][j], j);
        }

        f_(j, 0, m)
        {
            int k = a[i][j] * (r[j] - l[j] - 1);
            z = MAX(z, k);
        }

        max = MAX(max, z);
    }

    printf("%d\n", max);
    return 0;
}