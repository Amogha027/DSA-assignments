#include "musicplayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

mptr createMusicPlayer()
{
	mptr m = (musicplayer *)malloc(sizeof(musicplayer));
	assert(m != NULL);
	m->curr_song = NULL;
	m->head = NULL;
	m->tail = NULL;
	m->num = 0;

	return m;
}

int addSongToQueue(mptr m, sptr song)
{
	ptr l = (Queue *)malloc(sizeof(Queue));
	if (l == NULL)
		return 1;

	l->sing = song;
	if (m->head == NULL)
	{
		m->head = l;
		m->tail = l;
		l->next = NULL;
		l->prev = NULL;
	}
	else
	{
		ptr temp = m->tail;
		l->prev = temp;
		temp->next = l;
		m->tail = l;
		l->next = NULL;
	}
	(m->num)++;
	return 0;
}

int removeSongFromQueue(mptr m, int idx)
{
	int k = idx + 1;
	if (m->head == NULL || (k > m->num))
		return 1;

	ptr p = m->head;
	if (k == 1)
	{
		if (p->next == NULL)
		{
			m->head = NULL;
			m->tail = NULL;
		}
		else
		{
			ptr temp = p->next;
			temp->prev = NULL;
			m->head = temp;
		}
		free(p);
	}
	else
	{
		int n = 1;
		while (n < idx)
		{
			p = p->next;
			n++;
		}

		ptr del = p->next;
		if (del->next == NULL)
		{
			p->next = NULL;
			m->tail = p;
		}
		else
		{
			ptr temp = del->next;
			p->next = temp;
			temp->prev = p;
		}
		free(del);
	}
	(m->num)--;

	if (m->num == 0)
	{
		m->head = NULL;
		m->tail = NULL;
	}
	return 0;
}

int playSong(mptr m)
{
	if (m->head == NULL)
		return 1;
	else
	{
		ptr p = m->head;
		m->curr_song = p->sing;
		return removeSongFromQueue(m, 0);
	}
}

song *getCurrentSong(mptr m)
{
	return m->curr_song;
}