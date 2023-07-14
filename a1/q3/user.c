#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

user *createUser(char *name)
{
    user *c = (user *)malloc(sizeof(user));
    assert(c != NULL);
    c->player = (musicplayer *)malloc(sizeof(musicplayer));
    c->name = (char *)malloc(strlen(name) + 1);
    strcpy(c->name, name);
    c->head = NULL;
    c->tail = NULL;
    c->count = 0;

    return c;
}

int addSongToQueueUser(user *c, sptr s)
{
    return addSongToQueue(c->player, s);
}

int removeSongFromQueueUser(user *c, int k)
{
    return removeSongFromQueue(c->player, k);
}

int playSongUser(user *c)
{
    return playSong(c->player);
}

song *getCurrentSongUser(user *c)
{
    sptr s = getCurrentSong(c->player);
    return s;
}

int addLikedSong(user *c, sptr s)
{
    ptr l = (Queue *)malloc(sizeof(Queue));
    if (l == NULL)
        return 1;

    l->sing = s;
    if (c->head == NULL)
    {
        c->head = l;
        c->tail = l;
        l->next = NULL;
        l->prev = NULL;
    }
    else
    {
        ptr temp = c->tail;
        l->prev = temp;
        temp->next = l;
        c->tail = l;
        l->next = NULL;
    }
    (c->count)++;
    return 0;
}

int removeLikedSong(user *c, sptr s)
{
    if (c->head == NULL)
        return 1;

    int k = 0, z = 0;
    ptr ph = c->head;
    while (ph != NULL)
    {
        if (strcmp(ph->sing->name, s->name) == 0)
        {
            z++;
            break;
        }
        ph = ph->next;
        k++;
    }

    k++;
    if (k > c->count || z == 0)
        return 1;

    ptr p = c->head;
    if (k == 1)
    {
        if (p->next == NULL)
        {
            c->head = NULL;
            c->tail = NULL;
        }
        else
        {
            ptr temp = p->next;
            temp->prev = NULL;
            c->head = temp;
        }
        free(p);
    }
    else
    {
        int n = 1;
        while (n < k)
        {
            p = p->next;
            n++;
        }

        ptr del = p->next;
        if (del->next == NULL)
        {
            p->next = NULL;
            c->tail = p;
        }
        else
        {
            ptr temp = del->next;
            p->next = temp;
            temp->prev = p;
        }
        free(del);
    }
    (c->count)--;

    if (c->count == 0)
    {
        c->head = NULL;
        c->tail = NULL;
    }
    return 0;
}

int userCompatibility(user *c1, user *c2)
{
    int count = 0;
    ptr p1 = c1->head;
    while (p1 != NULL)
    {
        ptr p2 = c2->head;
        while (p2 != NULL)
        {
            if (strcmp(p1->sing->name, p2->sing->name) == 0)
                count++;
            p2 = p2->next;
        }
        printf("%d\n", count);
        p1 = p1->next;
    }

    return count;
}